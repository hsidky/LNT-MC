#include "ForceFieldManager.h"
#include "../Particles/NewParticle.h"
#include "../Worlds/NewWorld.h"

namespace SAPHRON
{
	void ForceFieldManager::AddNonBondedForceField(uint s1, uint s2, const NonBondedFF& ff)
	{
		// Resize and update vector / count if necessary.
		auto smax = std::max(s1, s2) + 1;
		if(smax > nbcount_)
		{
			nbcount_ = smax;
			nonbondedffs_.resize(smax*smax, nullptr);
		}

		// Get mapped index with symmetry.
		auto idx1 = GetIndex(s1, s2);
		auto idx2 = GetIndex(s2, s1);

		nonbondedffs_[idx1] = &ff;
		nonbondedffs_[idx2] = &ff;
	}

	void ForceFieldManager::RemoveNonBondedForceField(uint s1, uint s2)
	{
		auto smax = std::max(s1, s2) + 1;

		if(smax <= nbcount_)
		{
			auto idx1 = GetIndex(s1, s2);
			auto idx2 = GetIndex(s2, s1);
			nonbondedffs_[idx1] = nullptr;
			nonbondedffs_[idx2] = nullptr;
		}
	}

	EV ForceFieldManager::EvaluateInterEnergy(const NewParticle& p, const NewWorld& w) const
	{
		EV ev;
		for(size_t i = 0; i < p.SiteCount(); ++i)
			ev += EvaluateInterEnergy(p.GetSite(i), w);
		return ev;
	}

	EV ForceFieldManager::EvaluateInterEnergy(const Site& s, const NewWorld& w) const
	{
		EV ep;

		// Get appropriate references.
		auto& particles = w.GetParticles();
		auto& sites = w.GetSites();
		auto& C = w.GetCellVector();
		auto& Pc = w.GetCellPointer();
		auto& Pm = w.GetMaskPointer();
		
		auto wid = w.GetID();
		// Get current cell and loop through all interacting stripes.
		auto S = w.GetStripeCount();
		int mi = w.GetCellIndex(s.position);

		// Evaluate current cell. 
		for(auto i = Pc[mi]; i < Pc[mi + 1]; ++i)
		{
			auto& sj = sites[C[i]];
			if(s.pid == sj.pid)
				continue;

			// Get site-site distance.
			Vector3 rij = s.position - sj.position;
			w.ApplyMinimumImage(rij);
			auto rsq = rij.squaredNorm();

			// Get molecule-molecule distance.
			Vector3 rab = particles[s.pid].GetPosition() - particles[sj.pid].GetPosition();
			w.ApplyMinimumImage(rab);

			// Get forcefield index and evaluate nonbonded. 
			auto idx = GetIndex(s.species, sj.species);
			auto& ff = nonbondedffs_[idx];
			if(ff != nullptr)
			{
				auto ef = ff->Evaluate(s, sj, rij, rsq, wid);
				ep.vdw += ef.energy;
				ep.virial.noalias() += ef.force*rab.transpose();
			}
		}

		#pragma omp declare reduction (+ : EV : omp_out += omp_in ) initializer (omp_priv=EV())
		#pragma omp parallel for reduction(+:ep)
		for(int i = 0; i < S; ++i)
		{
			// First and last cells of stripe. 
			auto m1 = mi + Pm[2*i];
			auto m2 = mi + Pm[2*i+1];

			for(auto l = Pc[m1]; l < Pc[m2 + 1]; ++l)
			{
				auto& sj = sites[C[l]];

				// Skip species with same parent (intramolecular).
				if(s.pid == sj.pid)
					continue;

				// Get site-site distance.
				Vector3 rij = s.position - sj.position;
				w.ApplyMinimumImage(rij);
				auto rsq = rij.squaredNorm();

				// Get molecule-molecule distance.
				Vector3 rab = particles[s.pid].GetPosition() - particles[sj.pid].GetPosition();
				w.ApplyMinimumImage(rab);

				// Get forcefield index and evaluate nonbonded. 
				auto idx = GetIndex(s.species, sj.species);
				auto& ff = nonbondedffs_[idx];
				if(ff != nullptr)
				{
					auto ef = ff->Evaluate(s, sj, rij, rsq, wid);
					ep.vdw += ef.energy;
					ep.virial.noalias() += ef.force*rab.transpose();
				}
			}
		}

		ep.virial *= -1;

		return ep;
	}

	EV ForceFieldManager::EvaluateInterEnergy(const NewWorld& w) const
	{
		EV u;
		for(auto& s : w.GetSites())
			u += EvaluateInterEnergy(s, w);

		u.vdw *= 0.5;
		u.virial *= 0.5;

		return u;
	}

	EPTail ForceFieldManager::EvaluateTailEnergy(const NewWorld& w) const
	{
		auto& comp = w.GetSiteCompositions();
		auto wid = w.GetID();
		auto v = w.GetVolume();

		EPTail u;
		// Go through unique pairs of species.
		for(uint i = 0; i < nbcount_; ++i)
			for(uint j = i; j < nbcount_; ++j)
			{
				auto na = comp[i];
				auto nb = comp[j];
				auto idx = GetIndex(i, j);

				u.energy += na*nb*nonbondedffs_[idx]->EnergyTailCorrection(wid);
				u.pressure += na*nb*nonbondedffs_[idx]->PressureTailCorrection(wid);
			}

		u.energy *= 2.*M_PI/v;
		u.pressure *= 2.*M_PI/(3.*v*v);

		return u;
	}
}