#include "schema.h"

namespace SAPHRON
{
	//INSERT_DEF_HERE
	std::string SAPHRON::JsonSchema::ElasticCoeffOP = "{\"required\": [\"type\", \"mode\", \"xrange\", \"world\"], \"additionalProperties\": false, \"properties\": {\"mode\": {\"enum\": [\"twist\"], \"type\": \"string\"}, \"xrange\": {\"maxItems\": 2, \"items\": {\"type\": \"number\"}, \"minItems\": 2, \"type\": \"array\"}, \"world\": {\"minimum\": 0, \"type\": \"integer\"}, \"type\": {\"enum\": [\"ElasticCoeff\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::WangLandauOP = "{\"required\": [\"type\"], \"additionalProperties\": false, \"properties\": {\"type\": {\"enum\": [\"WangLandau\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::Histogram = "{\"required\": [\"min\", \"max\"], \"additionalProperties\": false, \"properties\": {\"binwidth\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"values\": {\"items\": {\"type\": \"number\"}, \"type\": \"array\"}, \"bincount\": {\"minimum\": 1, \"type\": \"integer\"}, \"counts\": {\"items\": {\"minimum\": 0, \"type\": \"integer\"}, \"type\": \"array\"}, \"max\": {\"type\": \"number\"}, \"min\": {\"type\": \"number\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::DOSSimulation = "{\"additionalProperties\": false, \"properties\": {\"reset_freq\": {\"minimum\": 0, \"type\": \"integer\"}, \"convergence_factor\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"target_flatness\": {\"exclusiveMaximum\": true, \"maximum\": 1, \"minimum\": 0, \"exclusiveMinimum\": true, \"type\": \"number\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::Simulation = "{\"required\": [\"simtype\", \"iterations\"], \"properties\": {\"units\": {\"enum\": [\"real\", \"reduced\"], \"type\": \"string\"}, \"simtype\": {\"enum\": [\"standard\", \"DOS\"], \"type\": \"string\"}, \"iterations\": {\"minimum\": 1, \"type\": \"integer\"}, \"mpi\": {\"minimum\": 1, \"type\": \"integer\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::ForceFields = "{\"additionalProperties\": false, \"properties\": {\"electrostatic\": {\"type\": \"array\"}, \"bonded\": {\"type\": \"array\"}, \"nonbonded\": {\"type\": \"array\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::HardSphereFF = "{\"required\": [\"type\", \"sigma\", \"species\"], \"additionalProperties\": false, \"properties\": {\"sigma\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"species\": {\"maxItems\": 2, \"additionalItems\": false, \"items\": {\"type\": \"string\"}, \"minItems\": 2, \"type\": \"array\"}, \"type\": {\"enum\": [\"HardSphere\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::FENEFF = "{\"required\": [\"type\", \"epsilon\", \"sigma\", \"kspring\", \"rmax\", \"species\"], \"additionalProperties\": false, \"properties\": {\"type\": {\"enum\": [\"FENE\"], \"type\": \"string\"}, \"rmax\": {\"minimum\": 0, \"type\": \"number\"}, \"sigma\": {\"minimum\": 0, \"type\": \"number\"}, \"epsilon\": {\"type\": \"number\"}, \"kspring\": {\"minimum\": 0, \"type\": \"number\"}, \"species\": {\"maxItems\": 2, \"additionalItems\": false, \"items\": {\"type\": \"string\"}, \"minItems\": 2, \"type\": \"array\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::DebyeHuckelFF = "{\"required\": [\"type\", \"kappa\", \"species\", \"rcut\"], \"additionalProperties\": false, \"properties\": {\"kappa\": {\"minimum\": 0, \"type\": \"number\"}, \"rcut\": {\"items\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"minItems\": 1, \"type\": \"array\"}, \"species\": {\"maxItems\": 2, \"additionalItems\": false, \"items\": {\"type\": \"string\"}, \"minItems\": 2, \"type\": \"array\"}, \"type\": {\"enum\": [\"DebyeHuckel\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::DSFFF = "{\"required\": [\"type\", \"alpha\", \"species\", \"rcut\"], \"additionalProperties\": false, \"properties\": {\"rcut\": {\"items\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"minItems\": 1, \"type\": \"array\"}, \"alpha\": {\"minimum\": 0, \"type\": \"number\"}, \"species\": {\"maxItems\": 2, \"additionalItems\": false, \"items\": {\"type\": \"string\"}, \"minItems\": 2, \"type\": \"array\"}, \"type\": {\"enum\": [\"DSF\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::LebwholLasherFF = "{\"required\": [\"type\", \"epsilon\", \"gamma\", \"species\"], \"additionalProperties\": false, \"properties\": {\"epsilon\": {\"type\": \"number\"}, \"species\": {\"maxItems\": 2, \"additionalItems\": false, \"items\": {\"type\": \"string\"}, \"minItems\": 2, \"type\": \"array\"}, \"gamma\": {\"type\": \"number\"}, \"type\": {\"enum\": [\"LebwohlLasher\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::LennardJonesTSFF = "{\"required\": [\"type\", \"sigma\", \"epsilon\", \"species\", \"rcut\"], \"additionalProperties\": false, \"properties\": {\"epsilon\": {\"minimum\": 0, \"type\": \"number\"}, \"rcut\": {\"items\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"minItems\": 1, \"type\": \"array\"}, \"sigma\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"species\": {\"maxItems\": 2, \"additionalItems\": false, \"items\": {\"type\": \"string\"}, \"minItems\": 2, \"type\": \"array\"}, \"type\": {\"enum\": [\"LennardJonesTS\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::LennardJonesFF = "{\"required\": [\"type\", \"sigma\", \"epsilon\", \"species\", \"rcut\"], \"additionalProperties\": false, \"properties\": {\"epsilon\": {\"minimum\": 0, \"type\": \"number\"}, \"rcut\": {\"items\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"minItems\": 1, \"type\": \"array\"}, \"sigma\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"species\": {\"maxItems\": 2, \"additionalItems\": false, \"items\": {\"type\": \"string\"}, \"minItems\": 2, \"type\": \"array\"}, \"type\": {\"enum\": [\"LennardJones\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::Components = "{\"items\": {\"maxItems\": 2, \"items\": [{\"type\": \"string\"}, {\"minimum\": 1, \"type\": \"integer\"}], \"minItems\": 2, \"type\": \"array\"}, \"minItems\": 1, \"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::Worlds = "{\"items\": {\"required\": [\"type\", \"dimensions\", \"nlist_cutoff\", \"skin_thickness\", \"components\"], \"additionalProperties\": false, \"properties\": {\"skin_thickness\": {\"minimum\": 0, \"type\": \"number\"}, \"nlist_cutoff\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"components\": {\"items\": {\"maxItems\": 2, \"items\": [{\"type\": \"string\"}, {\"minimum\": 1, \"type\": \"integer\"}], \"minItems\": 2, \"type\": \"array\"}, \"minItems\": 1, \"type\": \"array\"}, \"particles\": {\"type\": \"array\"}, \"type\": {\"enum\": [\"Simple\"], \"type\": \"string\"}, \"dimensions\": {\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"minimum\": 0, \"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}, \"temperature\": {\"minimum\": 0, \"type\": \"number\"}, \"pack\": {\"properties\": {\"count\": {\"minimum\": 1, \"type\": \"integer\"}, \"composition\": {\"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"maximum\": 1.0, \"minimum\": 0.0, \"exclusiveMinimum\": true, \"type\": \"number\"}}, \"type\": \"object\"}, \"density\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}}, \"type\": \"object\"}, \"chemical_potential\": {\"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"number\"}}, \"type\": \"object\"}}, \"type\": \"object\"}, \"minItems\": 1, \"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::SimpleWorld = "{\"required\": [\"type\", \"dimensions\", \"nlist_cutoff\", \"skin_thickness\", \"components\"], \"additionalProperties\": false, \"properties\": {\"skin_thickness\": {\"minimum\": 0, \"type\": \"number\"}, \"nlist_cutoff\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"components\": {\"items\": {\"maxItems\": 2, \"items\": [{\"type\": \"string\"}, {\"minimum\": 1, \"type\": \"integer\"}], \"minItems\": 2, \"type\": \"array\"}, \"minItems\": 1, \"type\": \"array\"}, \"particles\": {\"type\": \"array\"}, \"type\": {\"enum\": [\"Simple\"], \"type\": \"string\"}, \"dimensions\": {\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"minimum\": 0, \"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}, \"temperature\": {\"minimum\": 0, \"type\": \"number\"}, \"pack\": {\"properties\": {\"count\": {\"minimum\": 1, \"type\": \"integer\"}, \"composition\": {\"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"maximum\": 1.0, \"minimum\": 0.0, \"exclusiveMinimum\": true, \"type\": \"number\"}}, \"type\": \"object\"}, \"density\": {\"exclusiveMinimum\": true, \"minimum\": 0, \"type\": \"number\"}}, \"type\": \"object\"}, \"chemical_potential\": {\"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"number\"}}, \"type\": \"object\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::Particles = "{\"additionalItems\": false, \"items\": {\"maxItems\": 4, \"additionalItems\": false, \"items\": [{\"minimum\": 1, \"type\": \"integer\"}, {\"type\": \"string\"}, {\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"minimum\": 0, \"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}, {\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}, {\"type\": \"string\"}], \"minItems\": 3, \"type\": \"array\"}, \"minItems\": 1, \"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::Site = "{\"maxItems\": 4, \"additionalItems\": false, \"items\": [{\"minimum\": 1, \"type\": \"integer\"}, {\"type\": \"string\"}, {\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"minimum\": 0, \"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}, {\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}, {\"type\": \"string\"}], \"minItems\": 3, \"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::Blueprints = "{\"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"additionalProperties\": false, \"properties\": {\"charge\": {\"type\": \"number\"}, \"children\": {\"items\": {\"required\": [\"species\"], \"properties\": {\"mass\": {\"minimum\": 0, \"type\": \"number\"}, \"charge\": {\"type\": \"number\"}, \"species\": {\"type\": \"string\"}}, \"type\": \"object\"}, \"minItems\": 1, \"type\": \"array\"}, \"bonds\": {\"items\": {\"maxItems\": 2, \"items\": {\"minimum\": 0, \"type\": \"number\"}, \"minItems\": 2, \"type\": \"array\"}, \"type\": \"array\"}, \"mass\": {\"minimum\": 0, \"type\": \"number\"}}, \"minProperties\": 1, \"type\": \"object\"}}, \"additionalProperties\": false, \"minProperties\": 1, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::Selector = "{}";
	std::string SAPHRON::JsonSchema::Director = "{\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::Observers = "{\"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::XYZObserver = "{\"required\": [\"type\", \"prefix\", \"frequency\"], \"additionalProperties\": false, \"properties\": {\"prefix\": {\"type\": \"string\"}, \"frequency\": {\"minimum\": 1, \"type\": \"integer\"}, \"type\": {\"enum\": [\"XYZ\"], \"type\": \"string\"}}}";
	std::string SAPHRON::JsonSchema::JSONObserver = "{\"required\": [\"type\", \"prefix\", \"frequency\"], \"additionalProperties\": false, \"properties\": {\"prefix\": {\"type\": \"string\"}, \"frequency\": {\"minimum\": 1, \"type\": \"integer\"}, \"type\": {\"enum\": [\"JSON\"], \"type\": \"string\"}}}";
	std::string SAPHRON::JsonSchema::DLMFileObserver = "{\"required\": [\"type\", \"prefix\", \"frequency\", \"flags\"], \"additionalProperties\": false, \"properties\": {\"prefix\": {\"type\": \"string\"}, \"flags\": {\"properties\": {\"particle_id\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"histogram\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"dos_flatness\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_pxx\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"world_energy\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"particle\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"particle_species\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"hist_interval\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"particle_parent_id\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_pyz\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"world\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"world_temperature\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"energy_intraelect\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"hist_values\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"energy_intervdw\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_tensor\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"world_volume\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_pxz\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"hist_bin_count\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"simulation\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"hist_lower_outliers\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_tail\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"particle_position\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"world_pressure\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"energy_connectivity\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"world_density\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"particle_neighbors\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"hist_upper_outliers\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"world_chem_pot\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"energy_components\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_pzz\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_pyy\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_ideal\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"move_acceptances\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"dos_factor\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"particle_parent_species\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"hist_counts\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"pressure_pxy\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"energy_interelect\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"world_composition\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"particle_director\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"energy_intravdw\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"particle_species_id\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"iteration\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}, \"energy_bonded\": {\"maximum\": 1, \"minimum\": 0, \"type\": \"integer\"}}, \"type\": \"object\"}, \"delimiter\": {\"type\": \"string\"}, \"type\": {\"enum\": [\"DLMFile\"], \"type\": \"string\"}, \"frequency\": {\"minimum\": 1, \"type\": \"integer\"}, \"extension\": {\"type\": \"string\"}, \"colwidth\": {\"minimum\": 1, \"type\": \"integer\"}, \"fixedwmode\": {\"type\": \"boolean\"}}}";
	std::string SAPHRON::JsonSchema::AnnealChargeMove = "{\"required\": [\"type\", \"species\"], \"additionalProperties\": false, \"properties\": {\"explicit_draw\": {\"type\": \"boolean\"}, \"species\": {\"items\": {\"type\": \"string\"}, \"minItems\": 1, \"type\": \"array\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"type\": {\"enum\": [\"AnnealCharge\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::DeleteParticleMove = "{\"required\": [\"type\", \"species\"], \"additionalProperties\": false, \"properties\": {\"op_prefactor\": {\"tyoe\": \"boolean\"}, \"species\": {\"items\": {\"type\": \"string\"}, \"minimumItems\": 1, \"type\": \"array\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"type\": {\"enum\": [\"DeleteParticle\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::InsertParticleMove = "{\"required\": [\"type\", \"stash_count\", \"species\"], \"additionalProperties\": false, \"properties\": {\"op_prefactor\": {\"tyoe\": \"boolean\"}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"stash_count\": {\"minimum\": 1, \"type\": \"integer\"}, \"species\": {\"items\": {\"type\": \"string\"}, \"minimumItems\": 1, \"type\": \"array\"}, \"type\": {\"enum\": [\"InsertParticle\"], \"type\": \"string\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::VolumeSwapMove = "{\"required\": [\"type\", \"dv\"], \"additionalProperties\": false, \"properties\": {\"dv\": {\"minimum\": 0, \"type\": \"number\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"type\": {\"enum\": [\"VolumeSwap\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::RotateMove = "{\"required\": [\"type\", \"maxangle\"], \"additionalProperties\": false, \"properties\": {\"maxangle\": {\"maximum\": 6.283185307179586, \"minimum\": 0, \"exclusiveMinimum\": true, \"type\": \"number\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"type\": {\"enum\": [\"Rotate\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::TranslateMove = "{\"required\": [\"type\", \"dx\"], \"additionalProperties\": false, \"properties\": {\"explicit_draw\": {\"type\": \"boolean\"}, \"dx\": {\"oneOf\": [{\"minimum\": 0, \"type\": \"number\"}, {\"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"exclusiveMinimum\": true, \"minimum\": 0.0, \"type\": \"number\"}}, \"minProperties\": 1, \"type\": \"object\"}]}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"type\": {\"enum\": [\"Translate\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::DirectorRotateMove = "{\"required\": [\"type\"], \"additionalProperties\": false, \"properties\": {\"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"type\": {\"enum\": [\"DirectorRotate\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::SpeciesSwapMove = "{\"required\": [\"type\"], \"additionalProperties\": false, \"properties\": {\"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"type\": {\"enum\": [\"SpeciesSwap\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::ParticleSwapMove = "{\"required\": [\"type\"], \"additionalProperties\": false, \"properties\": {\"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"type\": {\"enum\": [\"ParticleSwap\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::Moves = "{\"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::RandomIdentityMove = "{\"required\": [\"type\", \"identities\"], \"additionalProperties\": false, \"properties\": {\"identities\": {\"items\": {\"type\": \"string\"}, \"uniqueItems\": true, \"minIems\": 1, \"type\": \"array\"}, \"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"type\": {\"enum\": [\"RandomIdentity\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::FlipSpinMove = "{\"required\": [\"type\"], \"additionalProperties\": false, \"properties\": {\"seed\": {\"minimum\": 0, \"type\": \"integer\"}, \"weight\": {\"minimum\": 1, \"type\": \"integer\"}, \"type\": {\"enum\": [\"FlipSpin\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::P2SAConnectivity = "{\"required\": [\"type\", \"coefficient\", \"director\", \"selector\"], \"additionalProperties\": false, \"properties\": {\"director\": {\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}, \"coefficient\": {\"type\": \"number\"}, \"selector\": {}, \"type\": {\"enum\": [\"P2SA\"], \"type\": \"string\"}}, \"type\": \"object\"}";
	std::string SAPHRON::JsonSchema::Connectivities = "{\"items\": {\"oneOf\": [{\"required\": [\"type\", \"coefficient\", \"director\", \"selector\"], \"additionalProperties\": false, \"properties\": {\"director\": {\"maxItems\": 3, \"additionalItems\": false, \"items\": {\"type\": \"number\"}, \"minItems\": 3, \"type\": \"array\"}, \"coefficient\": {\"type\": \"number\"}, \"selector\": {}, \"type\": {\"enum\": [\"P2SA\"], \"type\": \"string\"}}, \"type\": \"object\"}]}, \"type\": \"array\"}";
	
}