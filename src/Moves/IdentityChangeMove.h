#pragma once

#include "../Rand.h"
#include "Move.h"

namespace SAPHRON
{
	// Identity change move. This move merely changes the identity of a particle. Meaning that it is useful
	// when performing (semi)grand canonical simulations on spins or atoms, but NOT on moleucles or
	// composite particle types. The only thing altered is the species and string.
	class IdentityChangeMove : public Move
	{
		private:
			Particle* _particle;

			int _prevSpecies;

			Rand _rand;

			int _speciesCount;

		public:
			IdentityChangeMove(int speciesCount, int seed = 1337) :
				_particle(nullptr), _prevSpecies(0), _rand(seed), _speciesCount(speciesCount) {}

			// Reassigns the species of a site with a new random one.
			virtual void Perform(const ParticleList& particles) override
			{
				_particle = *particles.begin();

				// Record previous species
				_prevSpecies = _particle->GetSpeciesID();

				_particle->SetSpecies(_rand.int32() % _speciesCount);
			}

			// Undo the move on a site.
			void Undo() override
			{
				_particle->SetSpecies(_prevSpecies);
			}

			// Clone move.
			virtual Move* Clone() const override
			{
				return new IdentityChangeMove(
				               static_cast<const IdentityChangeMove&>(*this)
				               );
			}
	};
}
