#pragma once

#include "Neighbor.h"
#include "../Visitors/Visitable.h"
#include "../Connectivities/Connectivity.h"
#include "ParticleObserver.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <exception>

namespace SAPHRON
{
	// Particle position.
	struct Position
	{
		double x;
		double y;
		double z;

		inline bool operator==(const Position& rhs) const
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
		}

		inline double norm()
		{
			return sqrt(x*x + y*y + z*z);
		}
	};

	inline Position operator+(Position lhs, const Position& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs;
	} 


	inline Position operator-(Position lhs, const Position& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		return lhs;
	} 

	inline double anint( const double &x )
	{
		return ( x >= 0 ) ? floor( x + 0.5 ) : ceil( x - 0.5 );
	}

	// Particle event class.
	class ParticleEvent
	{
		private:
			Particle* _particle;

		public:
			ParticleEvent(Particle* particle) : _particle(particle), mask(0) {}

			union
			{
				struct
				{
					unsigned int position : 1;
					unsigned int director : 1;
					unsigned int species : 1;
					unsigned int neighbors : 1;
				};
				bool mask;
			};

			inline Particle* GetParticle() const
			{
				return _particle;
			}
	};

	typedef std::vector<double> Director;
	typedef std::list<Neighbor> NeighborList;
	typedef std::list<Neighbor>::iterator NeighborIterator;
	typedef std::vector<std::string> SpeciesList;
	typedef std::list<Connectivity*> ConnectivityList;
	typedef std::list<Connectivity*>::iterator ConnectivityIterator;
	typedef std::vector<Particle*> ParticleList;
	typedef std::map<int, Particle*> ParticleMap;

	// Abstract class Particle represents either a composite or primitive object, from an atom/site to
	// a molecule to a collection of molecules. It represents an common interface allowing the manipulation
	// of all of the above through a common interface.
	class Particle : public Visitable
	{
		private:

			// String species.
			std::string _species;

			// Integer species.
			int _speciesID;

			// Neighbor list.
			NeighborList _neighbors;

			// Observer list. 
			std::list<ParticleObserver*> _observers;

			// Global identifier.
			int _globalID;

			// Next ID counter for unique global species.
			static int _nextID;

			// Global list of particle species.
			static SpeciesList _speciesList;

			// Global list of particle id's and pointers.
			static ParticleMap _identityList;

			// Connectivities.
			ConnectivityList _connectivities;

			// Gets the next available global ID.
			int GetNextGlobalID()
			{
				int candidate = ++_nextID;
				if(_identityList.find(candidate) == _identityList.end())
					return candidate;
				else
					return GetNextGlobalID();
			}
		
		protected:

			// Particle event. 
			ParticleEvent _pEvent;

		public:

			// Initialize a particle with a particular species. This string represents the global type
			// species for this particle.
			Particle(std::string species) : 
			_species(species), _speciesID(0), _neighbors(), _observers(), 
			_globalID(SetGlobalIdentifier(GetNextGlobalID())), _connectivities(0), _pEvent(this)
			{
				SetSpecies(species);
			}

			// Copy constructor.
			Particle(const Particle& particle) : 
			_species(particle._species), _speciesID(particle._speciesID), _neighbors(particle._neighbors),
			_observers(particle._observers), _globalID(SetGlobalIdentifier(GetNextGlobalID())), _connectivities(particle._connectivities),
			_pEvent(this)
			{
			}

			virtual ~Particle() 
			{
				// Remove particle from map.
				_identityList.erase(_globalID);
			}

			// Get global particle species.
			inline int GetGlobalIdentifier() const
			{
				return _globalID;
			}

			// Set global particle species. If ID is taken, returns an alternative ID that is unique.
			inline int SetGlobalIdentifier(int id)
			{
				// ID MUST be unique. But make sure we are not re-assigning the same value.
				auto it = _identityList.find(id);
				if(it != _identityList.end() && it->second != this)
					id = GetNextGlobalID();

				// Clear previous ID and update new one.
				_identityList.erase(_globalID);
				_identityList[id] = this;

				_globalID = id;
				return id;
			}

			// Get reference to global particle map.
			static const ParticleMap& GetParticleMap()
			{
				return _identityList;
			}

			// Get particle species.
			inline int GetSpeciesID() const
			{
				return _speciesID;
			}

			// Get particle string species.
			inline std::string GetSpecies() const
			{
				return _species;
			}

			// Get identity list.
			static SpeciesList GetSpeciesList()
			{
				return _speciesList;
			}

			// Set the species of a particle.
			void SetSpecies(std::string species);

			// Set the species of a particle.
			void SetSpecies(int id);

			// Get particle position.
			virtual Position GetPosition() const = 0;

			// Get particle position reference.
			virtual const Position& GetPositionRef() const = 0;

			// Move a particle to a new set of coordinates.
			virtual void SetPosition(const Position& position) = 0;

			// Move a particle to a new set of coordinates.
			virtual void SetPosition(Position && position) = 0;

			// Get the particle director.
			virtual Director GetDirector() const = 0;

			// Get the particle director pointer.
			virtual const Director& GetDirectorRef() const = 0;

			// Set the particle director.
			virtual void SetDirector(const Director& director) = 0;

			// Set the particle director.
			virtual void SetDirector(Director&& director) = 0;

			// Set the particle director.
			virtual void SetDirector(double ux, double uy, double uz) = 0;

			// Gets neighbor list iterator.
			inline NeighborList& GetNeighbors()
			{
				return _neighbors;
			}

			// Add a neighbor to neighbor list.
			void AddNeighbor(Neighbor&& neighbor)
			{
				_neighbors.emplace_back(neighbor);
			}

			// Clear the neighbor list.
			void ClearNeighborList()
			{
				_neighbors.clear();
			}

			// Add a connectivity to the particle.
			void AddConnectivity(Connectivity* connectivity)
			{
				_connectivities.push_back(connectivity);
			}

			// Remove a connectivity from the particle.
			void RemoveConnectivity(Connectivity* connectivity)
			{
				_connectivities.remove(connectivity);
			}

			// Gets connectivity list.
			const ConnectivityList& GetConnectivities() const
			{
				return _connectivities;
			}

			// Add particle observer.
			void AddObserver(ParticleObserver* observer)
			{
				_observers.push_back(observer);
			}

			// Remove particle observer.
			void RemoveObserver(ParticleObserver* observer)
			{
				_observers.remove(observer);
			}

			// Notify registered particle observers of a change.
			void NotifyObservers()
			{
				for (auto observer : _observers)
					observer->Update(_pEvent);

				_pEvent.mask = false;
			}

			virtual void AcceptVisitor(Visitor &v) override
			{
				v.Visit(this);
			}

			// Gets all descendants of a particle.
			virtual std::vector<Particle*> GetChildren() = 0;

			// Clone particle.
			virtual Particle* Clone() const = 0;
	};
}
