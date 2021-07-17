//
// Created on 14/06/2021.
//

#include "force_registry.h"

#include <iostream>

void ForceRegistry::add(const std::shared_ptr<Particle>& p_particle, const std::shared_ptr<ForceGenerator>& p_fg)
{
    Registration registration;
    registration.particle = p_particle;
    registration.generator = p_fg;

    registry.push_back(registration);
}

void ForceRegistry::remove(const std::shared_ptr<Particle>& p_particle, const std::shared_ptr<ForceGenerator>& p_fg)
{
    for (auto it = registry.begin(); it != registry.end(); ++it)
    {
        if (it->particle == p_particle && it->generator == p_fg)
        {
            registry.erase(it);
        }
    }
}

void ForceRegistry::update_forces(real duration)
{
    for (auto it = registry.begin(); it != registry.end(); ++it)
    {
        it->generator->update_force(it->particle, duration);
    }
}
