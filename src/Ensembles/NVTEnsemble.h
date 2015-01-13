#pragma once

#include "../Models/BaseModel.h"
#include "Ensemble.h"
#include <iostream>

namespace Ensembles
{
    // Class for simple NVT ensemble - also known as "canonical" ensemble. This
    // calls moves off the move queue and uses the Metropolis algorithm for acceptance
    // probability, A(i->j) = min(1,exp(DE/kB*T)). The template represents the return
    // type of DrawSample from model, which should typically be Site.
    template <typename T>
    class NVTEnsemble : public Ensemble<T>
    {
        private:

          // Temperature (K) (Sometimes reduced).
          double _temperature;

          // "Normalized" Boltzmann constant.
          double _kb = 1.0;

        public:
            NVTEnsemble(BaseModel& model, double temperature) :
            Ensemble<T>(model), _temperature(temperature) {}

            void Iterate()
            {
                // Draw sample and evaluate Hamiltonian
                auto sample = this->model.DrawSample();
                double prevH = this->model.EvaluateHamiltonian(*sample);

                // Perform moves
                for(auto &move : this->moves)
                    move->Perform(*sample);

                // Get new Hamiltonian.
                double currH = this->model.EvaluateHamiltonian(*sample);

                // Check probabilities.
                if(AcceptanceProbability(prevH, currH) < this->model.GetRandomUniformProbability())
                {
                    for(auto &move : this->moves)
                      move->Undo();
                }

            };

            // Metropolis acceptance probability of the system transitioning from prevH
            // to currH via exp(-(currH-prevH)/kb*T).
            double AcceptanceProbability(double prevH, double currH)
            {
              auto p =
                    exp(-(currH - prevH) / (GetBoltzmannConstant() * GetTemperature()));

              return p > 1 ? 1 : p;
            }

            // Gets the temperature (K).
            double GetTemperature()
            {
              return this->_temperature;
            }

            // Sets the temperature (K).
            double SetTemperature(double temperature)
            {
              return this->_temperature = temperature;
            }

            // Gets the "normalized" Boltzmann constant (J/K).
            double GetBoltzmannConstant()
            {
              return this->_kb;
            }
    };

}