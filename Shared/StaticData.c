// Copyright (C) 2024 Paul Johnson
// Copyright (C) 2024-2025 Maxim Nesterov

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Shared/StaticData.h>

#include <math.h>
#include <stdio.h>

#include <Shared/Utilities.h>

// clang-format off
struct rr_petal_base_stat_scale const offensive[rr_rarity_id_max] = {
    {1.0, 1.0},
    {1.7, 2.0},
    {2.9, 4.0},
    {5.0, 8.0},
    {8.5,  16},
    {14.5, 48},
    {24.6,144},
    {42.0,432},
    {102,1512},
    {242,5292},
};

struct rr_petal_base_stat_scale const defensive[rr_rarity_id_max] = {
    {1.0, 1.0},
    {2.0, 1.7},
    {4.0, 2.9},
    {8.0, 5.0},
    {16,  8.5},
    {48, 14.5},
    {144,24.6},
    {432,42.0},
    {1512,102},
    {5292,242}
};

struct rr_petal_data RR_PETAL_DATA[rr_petal_id_max] = {
//   id                     min_rarity              scale        dmg      hp   clump   cd 2cd  count
    {rr_petal_id_none,      rr_rarity_id_common,    offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_basic,     rr_rarity_id_common,    offensive, 15.0f,  15.0f,   0.0f,  50,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_pellet,    rr_rarity_id_common,    offensive,  11.0f,   5.0f,   0.0f,  13,  0, {1,2,2,3,3,5,6,6,6,6}},
    {rr_petal_id_fossil,    rr_rarity_id_common,    offensive,  5.5f, 150.0f,   0.0f, 100,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_stinger,   rr_rarity_id_common,    offensive, 75.0f,   3.0f,  10.0f, 150,  0, {1,1,1,1,1,3,5,5,6,6}},
    {rr_petal_id_berry,     rr_rarity_id_rare,      offensive,  9.0f,   5.0f,  12.0f,  13,  0, {1,1,1,1,1,2,3,3,4,4}},
    {rr_petal_id_shell,     rr_rarity_id_rare,      offensive, 30.0f,  16.0f,   0.0f,  50, 13, {1,1,1,1,2,2,3,3,4,4}},
    {rr_petal_id_peas,      rr_rarity_id_rare,      offensive, 24.0f,  12.0f,   8.0f,  13, 12, {4,4,4,4,4,4,5,5,5,6}},
    {rr_petal_id_leaf,      rr_rarity_id_unusual,   offensive,  12.0f,  8.0f,   8.0f,  38,  0, {1,1,1,1,2,2,3,3,3,3}},
    {rr_petal_id_egg,       rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25,100, {4,4,3,3,3,2,2,2,2,2}},
    {rr_petal_id_magnet,    rr_rarity_id_unusual,   defensive,  2.0f,  25.0f,   0.0f,  38,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_uranium,   rr_rarity_id_rare,      offensive,  3.0f,  40.0f,   0.0f,  25, 25, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_feather,   rr_rarity_id_common,    defensive,  1.0f,   3.0f,   0.0f,  25,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_azalea,    rr_rarity_id_common,    defensive,  5.0f,  15.0f,  10.0f,  25, 50, {1,1,1,1,1,1,3,3,4,4}},
    {rr_petal_id_bone,      rr_rarity_id_common,    defensive,  2.5f,  25.0f,   0.0f,  68,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_web,       rr_rarity_id_rare,      defensive,  5.0f,   5.0f,   0.0f,  50, 13, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_seed,      rr_rarity_id_epic,      defensive,  1.0f,  75.0f,   0.0f,  63, 13, {1,1,1,1,1,1,1,1,2,2}},
    {rr_petal_id_gravel,    rr_rarity_id_unusual,   offensive,  12.0f,  25.0f,   0.0f,  20, 10, {1,2,2,2,3,3,4,4,5,5}},
    {rr_petal_id_club,      rr_rarity_id_common,    offensive,  3.0f,1400.0f,   0.0f, 200,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_crest,     rr_rarity_id_rare,      offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_droplet,   rr_rarity_id_common,    offensive, 15.0f,   5.0f,   0.0f,  37,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_beak,      rr_rarity_id_common,    defensive,  10.0f,   5.0f,   0.0f,  55,  0, {1,1,1,1,1,1,1,1,2,2}},
    {rr_petal_id_lightning, rr_rarity_id_unusual,   offensive,  11.0f,   1.0f,   0.0f,  50,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_third_eye, rr_rarity_id_legendary, offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_nest,      rr_rarity_id_rare,      defensive,  5.0f,  25.0f,   0.0f, 250, 13, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_fireball,  rr_rarity_id_unusual,   offensive,260.0f,   1.0f,   0.0f, 600,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_meat,      rr_rarity_id_common,    offensive,  0.0f,1700.0f,   0.0f, 188, 13, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_bubble,    rr_rarity_id_common,    defensive,  0.0f,  1000.0f,   0.0f, 150,  3,{1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_meteor,    rr_rarity_id_unusual,   defensive,  0.0f,   0.0f,   0.0f,  75,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_mandible,  rr_rarity_id_common,    offensive,  5.0f,  10.0f,   0.0f,  75,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_wax,       rr_rarity_id_unusual,   offensive, 10.0f,  10.0f,  10.0f,  38,  0, {2,2,2,2,2,2,2,2,3,3}},
    {rr_petal_id_sand,      rr_rarity_id_common,    offensive,  11.0f,  10.0f,  10.0f,  20,  0, {4,4,4,4,4,4,4,4,5,5}},
    {rr_petal_id_mint,      rr_rarity_id_unusual,   offensive,  5.0f,  10.0f,  10.0f,  50, 25, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_dako_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25, 50, {6,5,5,5,4,4,4,4,3,3}},
    {rr_petal_id_pter_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25, 50, {6,5,5,4,4,4,3,3,3,3}},
    {rr_petal_id_fern_egg,  rr_rarity_id_common,    defensive,  1.0f,  75.0f,  10.0f,  25, 25, {6,6,6,5,5,4,3,2,2,2}},
    {rr_petal_id_tree_egg,  rr_rarity_id_common,    defensive,  1.0f,  75.0f,  10.0f,  25, 150, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_anky_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25, 75, {5,5,4,4,3,3,3,3,2,2}},
    {rr_petal_id_trice_egg,  rr_rarity_id_unusual,  defensive,  1.0f,  75.0f,  10.0f,  25, 50, {5,5,5,4,4,3,3,3,3,3}},
    {rr_petal_id_quetz_egg,  rr_rarity_id_unusual,  defensive,  1.0f,  75.0f,  10.0f,  25, 75, {4,4,4,3,3,3,2,2,2,2}},
    {rr_petal_id_edmo_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25, 75, {4,4,4,4,3,3,3,2,2,2}},
    {rr_petal_id_pachy_egg,  rr_rarity_id_unusual,  defensive,  1.0f,  75.0f,  10.0f,  25, 75, {4,4,4,4,3,3,3,2,2,2}},
    {rr_petal_id_orni_egg,  rr_rarity_id_common,    defensive,  1.0f,  75.0f,  10.0f,  25, 150, {3,3,2,2,1,1,1,1,1,1}},
    {rr_petal_id_obliterator,rr_rarity_id_common,   offensive, 1000000000.0f,  1000000000.0f,   0.0f,  0,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_eggOP,       rr_rarity_id_unusual, defensive,  1.0f,  75.0f,  10.0f,  0,0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_eggTest,    rr_rarity_id_unusual,  defensive,  1.0f,  75.0f,  10.0f,  25,100, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_permastun,   rr_rarity_id_common,  defensive,  0.0f,  1000000000.0f,  0.0f,  0.0,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_superfling,  rr_rarity_id_common,  defensive,  0.0f,  1000000000.0f,  0.0f,  0.0,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_permastun_obtainable,rr_rarity_id_common,defensive,  0.0f,  10.0f,  0.0f,  750,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_rice,      rr_rarity_id_common,    offensive,  6.0f,   1.0f,   0.0f,   1,  0, {1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_missile,   rr_rarity_id_rare,      offensive,  25.0f,   2.0f,   0.0f,  10,  5, {1,1,1,1,1,1,1,1,1,1}},

};    

char const *RR_PETAL_NAMES[rr_petal_id_max] = {
    "Secret",   "Petal",     "Pellet",    "Fossil", "Stinger",  "Berry",   "Shell",
    "Peas",     "Leaf",      "T-rex Egg",       "Magnet", "Uranium",  "Feather", "Azalea",
    "Bone",     "Web",       "Seed",      "Gravel", "Club",     "Crest",   "Droplet",
    "Beak",     "Lightning", "Third Eye", "Nest",   "Fireball", "Meat",    "Bubble",
    "Meteor",   "Mandible",  "Wax",       "Sand",   "Mint", "Dako Egg", "Pter Egg",
    "Fern Egg", "Tree Egg", "Anky Egg", "Trice Egg", "Quetz Egg", "Edmo Egg", "Pachy Egg", "Orni Egg",
    "Obliterator", "OP egg", "Test egg", "Permastun Dev", "Superfling", "Permastun", "Rice", "Missile",
};
char const *RR_PETAL_DESCRIPTIONS[rr_petal_id_max] = {
    0,
    "It's just a petal",
    "Low damage, but there's lots",
    "It came from a dino",
    "Ow that hurts",
    "Gives your other petals more energy",
    "Poor snail",
    "Splits in 4. Or maybe 5 if you're a pro",
    "Heals you gradually",
    "Spawns a pet T-rex to protect you",
    "Increases loot pickup radius. Stacks diminishingly",
    "Does damage to the owner and enemies in a large range",
    "It's so light it increases your movement speed. Stacks diminishingly",
    "It heals you",
    "Gives the player armor. Stacks diminishingly",
    "It slows everything down",
    "What does this one do",
    "Tiny rocks that stay on the ground and trip dinos",
    "Heavy and sturdy",
    "Increases your maximum vision range. Stacks diminishingly",
    "This mysterious petal reverses your petal rotation",
    "Stuns mobs and prevents them from moving",
    "A stunning display",
    "Your petals hate it and want to move further away. Stacks diminishingly",
    "Home sweet home",
    "Nice ball bro",
    "Meat meta",
    "Pop and you're gone. Does not stack",
    "Spawns a pet meteor to protect you",
    "Does more damage if target hp is below 50%",
    "Made by the bees",
    "Very fine",
    "Remember to feed your pets",
    "Spawns a pet dakotaraptor to protect you",
    "Spawns a pet pteranodon to protect you",
    "OP afk",
    "Where did this come from?",
    "Spawns a pet ankylosaurus to protect you",
    "Spawns a pet triceratops to protect you",
    "Spawns a pet quetzalcoatlus to protect you",
    "Spawns a pet edmontosaurus to protect you",
    "Spawns a pet pachycephalosaurus to protect you",
    "Spawns a pet ornithomimus to protect you", 
    "Obliterate any enemy. Dev-only petal.",
    "OP. Spawns a pet T-rex to protect you. Dev-only petal.",
    "Test. Dev-only petal.",
    "Permanently stuns enemies. Dev-only petal.",
    "Flings enemies very far away. Dev-only petal.",
    "Permanently stuns enemies.",
    "Chinese love it.",
    "Shell copycat."
};

struct rr_mob_data RR_MOB_DATA[rr_mob_id_max] = {
//   id                                     min_rarity  max_rarity              hp dmg    rad  ai_passive_rarity    ai_neutral_rarity    ai_aggro_rarity       loot
    {rr_mob_id_triceratops,        rr_rarity_id_common, rr_rarity_id_astral,  45, 15, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_leaf,    0.15},{rr_petal_id_fossil,    0.05},{rr_petal_id_trice_egg,      0.1}}},
    {rr_mob_id_trex,               rr_rarity_id_common, rr_rarity_id_astral,  40, 25, 32.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_unusual, {{rr_petal_id_stinger, 0.03},{rr_petal_id_egg,       0.05},{rr_petal_id_meat,      0.01}, {rr_petal_id_permastun_obtainable, 0.0015}}},
    {rr_mob_id_fern,               rr_rarity_id_common, rr_rarity_id_astral,  10,  5, 24.0f, rr_rarity_id_max,    rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_leaf,     0.1},{rr_petal_id_azalea,    0.25},{rr_petal_id_fern_egg,  0.13}, {rr_petal_id_mint, 0.1}}},
    {rr_mob_id_tree,               rr_rarity_id_common, rr_rarity_id_astral, 100,  5, 64.0f, rr_rarity_id_max,    rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_leaf,     2.5},{rr_petal_id_peas,       2.5},{rr_petal_id_seed,      0.05}, {rr_petal_id_tree_egg, 0.06}}},
    {rr_mob_id_pteranodon,         rr_rarity_id_common, rr_rarity_id_astral,  40, 15, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_rare,    {{rr_petal_id_shell,   0.05},{rr_petal_id_beak,      0.15},{rr_petal_id_nest,      0.01}, {rr_petal_id_pter_egg,0.1}}},
    {rr_mob_id_dakotaraptor,       rr_rarity_id_common, rr_rarity_id_astral,  35, 10, 25.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_epic,    {{rr_petal_id_crest,    0.1},{rr_petal_id_feather,    0.1},{rr_petal_id_pellet,    0.05},{rr_petal_id_dako_egg, 0.1}}},
    {rr_mob_id_pachycephalosaurus, rr_rarity_id_common, rr_rarity_id_astral,  35, 20, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_common,  {{rr_petal_id_fossil,   0.1},{rr_petal_id_berry,      0.1},{rr_petal_id_web,       0.05}, {rr_petal_id_pachy_egg, 0.08}}},
    {rr_mob_id_ornithomimus,       rr_rarity_id_common, rr_rarity_id_astral,  25, 10, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_feather,  0.1},{rr_petal_id_droplet,   0.05},{rr_petal_id_pellet,     0.1}, {rr_petal_id_orni_egg, 0.12}}},
    {rr_mob_id_ankylosaurus,       rr_rarity_id_common, rr_rarity_id_astral,  50, 10, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,      {{rr_petal_id_club,    0.15},{rr_petal_id_gravel,    0.05},{rr_petal_id_bubble,     0.1}, {rr_petal_id_anky_egg, 0.1}}},
    {rr_mob_id_meteor,             rr_rarity_id_common, rr_rarity_id_astral, 100, 10, 32.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_magnet,   0.5},{rr_petal_id_uranium,   0.05},{rr_petal_id_fireball,   1.0},{rr_petal_id_meteor, 2.0}}},
    {rr_mob_id_quetzalcoatlus,     rr_rarity_id_common, rr_rarity_id_astral,  65, 20, 28.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_common,  {{rr_petal_id_beak,    0.05},{rr_petal_id_fossil,     0.1},{rr_petal_id_lightning, 0.01}, {rr_petal_id_quetz_egg, 0.07}}},
    {rr_mob_id_edmontosaurus,      rr_rarity_id_common, rr_rarity_id_astral,  50, 15, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_bone,    0.01},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}, {rr_petal_id_edmo_egg, 0.1}}},
    {rr_mob_id_ant,                rr_rarity_id_common, rr_rarity_id_astral,  100, 10, 20.0f, rr_rarity_id_common, rr_rarity_id_common,    rr_rarity_id_exotic,     {{rr_petal_id_rice,   0.1},{rr_petal_id_leaf,       0.1},{rr_petal_id_mandible,  0.05}}},
    {rr_mob_id_hornet,             rr_rarity_id_common, rr_rarity_id_astral,  30, 30, 25.0f, rr_rarity_id_common, rr_rarity_id_common,    rr_rarity_id_unusual,     {{rr_petal_id_missile,  0.1},{rr_petal_id_crest,     0.05}}},
    {rr_mob_id_dragonfly,          rr_rarity_id_common, rr_rarity_id_astral,  40, 10, 25.0f, rr_rarity_id_common, rr_rarity_id_common,    rr_rarity_id_legendary,     {{rr_petal_id_bubble,   0.1},{rr_petal_id_magnet,    0.05}}},
    {rr_mob_id_honeybee,           rr_rarity_id_common, rr_rarity_id_astral,  20, 30, 22.0f, rr_rarity_id_common, rr_rarity_id_common,    rr_rarity_id_max,     {{rr_petal_id_wax,     0.1},{rr_petal_id_stinger,   0.02}}},
    {rr_mob_id_beehive,            rr_rarity_id_common, rr_rarity_id_astral,   0,  0, 45.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_wax,     0.05},{rr_petal_id_azalea,    0.05}}},
    {rr_mob_id_spider,             rr_rarity_id_common, rr_rarity_id_astral,  20, 25, 25.0f, rr_rarity_id_common, rr_rarity_id_common,    rr_rarity_id_common,     {{rr_petal_id_web,      0.1},{rr_petal_id_third_eye, 0.01}, {rr_petal_id_berry, 0.08}}},
    {rr_mob_id_house_centipede,    rr_rarity_id_common, rr_rarity_id_astral,  25, 10, 23.0f, rr_rarity_id_common, rr_rarity_id_common,    rr_rarity_id_legendary,     {{rr_petal_id_peas,     0.1},{rr_petal_id_sand,      0.05}}},
    {rr_mob_id_lanternfly,         rr_rarity_id_common, rr_rarity_id_astral,  30, 15, 25.0f, rr_rarity_id_common, rr_rarity_id_common,    rr_rarity_id_epic,     {{rr_petal_id_mint,     0.1},{rr_petal_id_sand,      0.05}}},
};

char const *RR_MOB_NAMES[rr_mob_id_max] = {
"Triceratops","T-Rex","Fern","Tree","Pteranodon","Dakotaraptor",
"Pachycephalosaurus","Ornithomimus","Ankylosaurus","Meteor",
"Quetzalcoatlus","Edmontosaurus","Ant","Hornet","Dragonfly",
"Honeybee","Beehive","Spider","House Centipede","Lanternfly"
};

uint32_t RR_MOB_DIFFICULTY_COEFFICIENTS[rr_mob_id_max] = {
    3, //tric
    4, //trex
    1, //fern
    2, //tree
    5, //pter
    5, //dako
    3, //pachy
    2, //ornith
    4, //anky
    1, //meteor
    5, //quetz
    3, //edmo
    1, //ant
    4, //hornet
    2, //dragonfly
    1, //bee
    5, //hive
    4, //spider
    6, //centi
    3, //lanternfly
};

double RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {
    50,   //tric
    100,  //trex
    15,   //fern
    0.25, //tree
    75,   //pter
    50,   //dako
    25,   //pachy
    40,   //ornith
    25,   //anky
    1,    //meteor
    75,   //quetz
    25,   //edmo
    
};
double RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 10};

struct rr_petal_rarity_scale RR_PETAL_RARITY_SCALE[rr_rarity_id_max] = {
    {1,    240, 45 },
    {1.8,  120, 60 },
    {3.5,  60,  75 },
    {6.8,  30,  100},
    {12.5, 15,  125},
    {24.5, 7.5, 150},
    {60,   2.5, 200},
    {180,  0.5, 250},
    {540,  1.5, 350},
    {1620, 0.75,450}
};

struct rr_mob_rarity_scale RR_MOB_RARITY_SCALING[rr_rarity_id_max] = {
    {1,      1,    1  },
    {2.4,    1.7,  1.2},
    {6,      2.9,  1.5}, 
    {14.4,   5,    2  },
    {40,     8.5,  2.8},
    {192,    14.5, 4  },
    {2560,   24.6, 5.5},
    {27400,  42,   7  },
    {262000, 102, 10},
    {2408400,242, 14}
};
// clang-format on

uint32_t RR_RARITY_COLORS[rr_rarity_id_max] = {
    0xff7eef6d, 0xffffe65d, 0xff4d52e3, 0xff861fde,
    0xffde1f1f, 0xff1fdbde, 0xffff2b75, 0xff2bffa3, 
    0xff3000af, 0xffffff9f};

char const *RR_RARITY_NAMES[rr_rarity_id_max] = {
    "Common",    "Unusual", "Rare",   "Epic",
    "Legendary", "Mythic",  "Exotic", "Ancient", 
    "Eternal", "Astral"};

long double RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_max + 1] = {
    0, 1, 6, 10, 15, 25, 160, 1200, 250, 100, 70};              

double RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_max] = {
       0, 1, 3, 8, 20, 20, 1700, 200, 500, 60
};
double RR_MOB_LOOT_RARITY_COEFFICIENTS[rr_rarity_id_max] = {
    2.5, 4,  6,   15, 35,  50, 125, 200, 275, 50
};

// static void init_game_coefficients()
// {
//     double sum = 1;
//     double sum2 = 1;
//     for (uint64_t a = 1; a < rr_rarity_id_max; ++a)
//         RR_MOB_LOOT_RARITY_COEFFICIENTS[a] *=
//             RR_MOB_LOOT_RARITY_COEFFICIENTS[a - 1];
//     for (uint64_t a = 1; a <= rr_rarity_id_exotic + 2; ++a)
//     {
//         sum += (RR_DROP_RARITY_COEFFICIENTS[a + 1] =
//                     RR_DROP_RARITY_COEFFICIENTS[a] /
//                     RR_DROP_RARITY_COEFFICIENTS[a + 1]);
//     }
//     for (uint64_t a = 1; a <= rr_rarity_id_exotic + 3; ++a)
//     {
//         RR_DROP_RARITY_COEFFICIENTS[a] = RR_DROP_RARITY_COEFFICIENTS[a] / sum +
//                                          RR_DROP_RARITY_COEFFICIENTS[a - 1];
//     }
    
//     RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_exotic + 3] = 1;
//     for (uint64_t a = 1; a <= rr_rarity_id_ultimate + 2; ++a)
//     {
//         sum2 += (RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1] =
//                      RR_MOB_WAVE_RARITY_COEFFICIENTS[a] /
//                      RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1]);
//     }
//     for (uint64_t a = 1; a <= rr_rarity_id_ultimate + 3; ++a)
//     {
//         RR_MOB_WAVE_RARITY_COEFFICIENTS[a] =
//             RR_MOB_WAVE_RARITY_COEFFICIENTS[a] / sum2 +
//             RR_MOB_WAVE_RARITY_COEFFICIENTS[a - 1];
//     }
//     RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_ultimate + 3] = 1;
//     for (uint64_t mob = 1; mob < rr_mob_id_max; ++mob)
//     {
//         RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] +=
//             RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
//         RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] +=
//             RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
//     }
//     for (uint64_t mob = 0; mob < rr_mob_id_max; ++mob)
//     {
//         RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] /=
//             RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
//         RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] /=
//             RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
//     }
// }

static void init_game_coefficients()
{
    long double sum = 1;
    long double sum2 = 1;
    for (uint64_t a = 1; a < rr_rarity_id_max; ++a)
        RR_MOB_LOOT_RARITY_COEFFICIENTS[a] *=
            RR_MOB_LOOT_RARITY_COEFFICIENTS[a - 1];
    for (uint64_t a = 1; a <= rr_rarity_id_max - 2; ++a)
    {
        sum += (RR_DROP_RARITY_COEFFICIENTS[a + 1] =
                    RR_DROP_RARITY_COEFFICIENTS[a] /
                    RR_DROP_RARITY_COEFFICIENTS[a + 1]);
    }
    for (uint64_t a = 1; a <= rr_rarity_id_max - 1; ++a)
    {
        RR_DROP_RARITY_COEFFICIENTS[a] = RR_DROP_RARITY_COEFFICIENTS[a] / sum +
                                         RR_DROP_RARITY_COEFFICIENTS[a - 1];
    }
    
    RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_max - 1] = 1;
    for (uint64_t a = 1; a <= rr_rarity_id_max - 1; ++a)
    {
        sum2 += (RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1] =
                     RR_MOB_WAVE_RARITY_COEFFICIENTS[a] /
                     RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1]);
    }
    for (uint64_t a = 1; a <= rr_rarity_id_max; ++a)
    {
        RR_MOB_WAVE_RARITY_COEFFICIENTS[a] =
            RR_MOB_WAVE_RARITY_COEFFICIENTS[a] / sum2 +
            RR_MOB_WAVE_RARITY_COEFFICIENTS[a - 1];
    }
    RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_max] = 1;
    for (uint64_t mob = 1; mob < rr_mob_id_max; ++mob)
    {
        RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
        RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
    }
    for (uint64_t mob = 0; mob < rr_mob_id_max; ++mob)
    {
        RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
        RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
    }
}
#define offset(a, b)                                                           \
    ((x + a < 0 || y + b < 0 || x + a >= size / 2 || y + b >= size / 2)        \
         ? 0                                                                   \
         : template[(y + b) * size / 2 + x + a])
#define maze_grid(x, y) maze[(y)*size + (x)]

static void init_maze(uint32_t size, uint8_t *template,
                      struct rr_maze_grid *maze)
{
    for (int32_t y = 0; y < size / 2; ++y)
    {
        for (int32_t x = 0; x < size / 2; ++x)
        {
            uint8_t this_tile = offset(0, 0);
            maze_grid(x * 2, y * 2).difficulty = this_tile;
            maze_grid(x * 2 + 1, y * 2).difficulty = this_tile;
            maze_grid(x * 2, y * 2 + 1).difficulty = this_tile;
            maze_grid(x * 2 + 1, y * 2 + 1).difficulty = this_tile;
            this_tile = this_tile != 0;
            // top left
            uint8_t top = offset(0, -1);
            uint8_t bottom = offset(0, 1);
            if (this_tile)
            {
                if (top == 0)
                {
                    if (offset(-1, 0) == 0)
                        maze_grid(x * 2, y * 2).value = 7;
                    else
                        maze_grid(x * 2, y * 2).value = this_tile;
                    if (offset(1, 0) == 0)
                        maze_grid(x * 2 + 1, y * 2).value = 5;
                    else
                        maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                if (bottom == 0)
                {
                    if (offset(-1, 0) == 0)
                        maze_grid(x * 2, y * 2 + 1).value = 6;
                    else
                        maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    if (offset(1, 0) == 0)
                        maze_grid(x * 2 + 1, y * 2 + 1).value = 4;
                    else
                        maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
            }
            else
            {
                if (top)
                {
                    if (offset(-1, 0) && offset(-1, -1))
                        maze_grid(x * 2, y * 2).value = 15;
                    else
                        maze_grid(x * 2, y * 2).value = this_tile;
                    if (offset(1, 0) && offset(1, -1))
                        maze_grid(x * 2 + 1, y * 2).value = 13;
                    else
                        maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                if (bottom)
                {
                    if (offset(-1, 0) && offset(-1, 1))
                        maze_grid(x * 2, y * 2 + 1).value = 14;
                    else
                        maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    if (offset(1, 0) && offset(1, 1))
                        maze_grid(x * 2 + 1, y * 2 + 1).value = 12;
                    else
                        maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
            }
        }
    }
}

static void print_chances(float difficulty)
{
    printf("-----Chances for %.0f-----\n", difficulty);
    uint32_t rarity_cap = rr_rarity_id_common + (difficulty + 7) / 8;
    if (rarity_cap > rr_rarity_id_astral)
        rarity_cap = rr_rarity_id_astral;
    uint32_t rarity = rarity_cap >= rr_rarity_id_eternal ? rarity_cap - 3 : rarity_cap >= 2 ? rarity_cap - 2 : 0;
    for (; rarity <= rarity_cap; ++rarity)
    {
        long double start =
            rarity == 0
                ? 0
                : powl(1 - (1 - RR_MOB_WAVE_RARITY_COEFFICIENTS[rarity]) * 0.3L,
                       powl(1.5L, (long double)difficulty));
        long double end =
            rarity == rarity_cap
                ? 1
                : powl(1 - (1 - RR_MOB_WAVE_RARITY_COEFFICIENTS[rarity + 1]) *
                          0.3L,
                       powl(1.5L, (long double)difficulty));
        long double chance = end - start;
        printf("%s: %.9Lf (1 per %.4Lf)\n", RR_RARITY_NAMES[rarity], chance,
               1 / chance);
    }
}

double RR_BASE_CRAFT_CHANCES[rr_rarity_id_max - 1] = {0.7,  0.5,  0.25, 0.16,
                                                      0.09, 0.07, 0.05, 0.03, 0.02};
double RR_CRAFT_CHANCES[rr_rarity_id_max - 1];

static double from_prd_base(double C)
{
    double pProcOnN = 0;
    double pProcByN = 0;
    double sumNpProcOnN = 0;

    double maxFails = ceil(1 / C);
    for (uint32_t N = 1; N <= maxFails; ++N)
    {
        pProcOnN = fmin(1, N * C) * (1 - pProcByN);
        pProcByN += pProcOnN;
        sumNpProcOnN += N * pProcOnN;
    }
    return (1 / sumNpProcOnN);
}

static double get_prd_base(double p)
{
    if (p == 0)
        return 0;
    double Cupper = p;
    double Clower = 0;
    double Cmid = p / 2;
    double p1 = 0;
    double p2 = 1;
    while (1)
    {
        Cmid = (Cupper + Clower) / 2;
        p1 = from_prd_base(Cmid);
        if (fabs(p1 - p2) <= 0)
            break;

        if (p1 > p)
            Cupper = Cmid;
        else
            Clower = Cmid;
        p2 = p1;
    }
    return Cmid;
}

#define init(MAZE)                                                             \
    init_maze(sizeof(RR_MAZE_##MAZE[0]) / sizeof(struct rr_maze_grid),         \
              &RR_MAZE_TEMPLATE_##MAZE[0][0], &RR_MAZE_##MAZE[0][0]);

void rr_static_data_init()
{
    for (uint32_t r = 0; r < rr_rarity_id_max - 1; ++r)
        RR_CRAFT_CHANCES[r] = get_prd_base(RR_BASE_CRAFT_CHANCES[r]);
    init_game_coefficients();
    init(HELL_CREEK);
    init(BURROW);
#ifdef RR_SERVER
    print_chances(1);  // c
    print_chances(4);  // C
    print_chances(8);  // u
    print_chances(12); // U
    print_chances(16); // r
    print_chances(20); // R
    print_chances(24); // e
    print_chances(28); // E
    print_chances(32); // l
    print_chances(36); // L
    print_chances(40); // m
    print_chances(44); // M
    print_chances(48); // x
    print_chances(52); // X
    print_chances(56); // a
    print_chances(60); // A
    print_chances(64); // t
    print_chances(68); // T
    print_chances(72); // s
    print_chances(76); // S
#endif
}

double xp_to_reach_level(uint32_t level)
{
    if (level <= 60)
        return (level + 5) * pow(1.175, level);
    double base = (level + 5) * pow(1.175, 60);
    for (uint32_t i = 60; i < level; ++i)
        base *= rr_fclamp(1.18 - 0.0075 * (i - 60), 1.1, 1.18);
    return base;
}

uint32_t level_from_xp(double xp)
{
    uint32_t level = 1;
    while (xp >= xp_to_reach_level(level + 1))
        xp -= xp_to_reach_level(++level);
    return level;
}

#define _ 0
#define c 1
#define C 4
#define u 8
#define U 12
#define r 16
#define R 20
#define e 24
#define E 28
#define l 32
#define L 36
#define m 40
#define M 44
#define x 48
#define X 52
#define a 56
#define A 60
#define t 64
#define T 68
#define s 72
#define S 76
#define RR_DEFINE_MAZE(name, size)                                             \
    struct rr_maze_grid RR_MAZE_##name[size][size];                            \
    uint8_t RR_MAZE_TEMPLATE_##name[size / 2][size / 2]
// clang-format off
RR_DEFINE_MAZE(HELL_CREEK, 80) = {
//                     11  13  15  17  19  21  23  25  27  29  31  33  35  37  39
// 1 2 3 4 5 6 7 8 9 10  12  14  16  18  20  22  24  26  28  30  32  34  36  38
/*{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}, // 0
{_,A,A,A,A,A,_,_,X,X,X,X,x,x,x,x,x,x,x,x,x,x,x,M,M,M,M,M,M,M,M,M,M,M,M,M,M,x,x,_}, // 1
{_,A,A,A,_,_,_,X,X,X,X,_,_,x,x,x,_,_,_,x,_,x,x,_,_,_,M,_,_,M,_,_,M,M,M,x,_,_,x,_}, // 2
{_,A,A,a,a,_,_,X,X,X,_,_,X,X,x,_,_,x,x,x,x,x,_,_,M,M,M,M,_,M,M,_,_,_,x,x,x,_,_,_}, // 3
{_,A,_,a,a,a,_,_,X,_,_,X,X,X,_,_,x,x,x,x,_,x,_,M,M,M,_,M,M,M,M,M,_,x,x,x,x,x,_,_}, // 4
{_,A,_,_,a,a,a,_,_,_,X,X,X,_,_,X,x,x,_,x,x,x,_,M,M,_,_,_,_,M,M,_,_,x,x,x,x,x,_,_}, // 5
{_,_,_,_,_,a,a,_,_,X,X,X,_,_,X,X,X,_,_,x,_,x,_,M,M,_,x,x,_,_,m,_,_,_,X,X,X,_,_,_}, // 6
{_,_,_,_,a,a,_,_,X,X,X,_,_,X,X,X,_,_,x,x,x,x,_,M,M,M,x,x,x,_,m,_,M,_,_,X,_,_,m,_}, // 7
{_,_,_,a,a,_,_,a,X,X,_,_,_,_,X,X,X,_,_,_,x,x,_,M,M,_,x,x,x,_,m,_,m,m,_,_,_,m,m,_}, // 8
{_,_,X,X,_,_,a,a,a,_,_,x,_,_,X,X,X,X,X,_,x,x,_,_,M,_,_,x,x,_,m,_,m,m,m,m,_,_,L,_}, // 9
{_,X,X,_,_,a,a,a,_,_,x,x,_,X,X,_,_,_,X,_,x,X,X,_,M,M,_,_,_,_,m,_,_,m,m,m,m,_,L,_}, // 10
{_,X,X,_,a,a,a,_,_,x,x,x,_,X,X,_,a,X,X,_,X,X,X,_,_,m,m,m,m,m,m,m,m,m,m,m,L,L,L,_}, // 11
{_,X,X,_,_,a,a,_,x,x,x,x,_,X,X,_,_,_,X,_,X,_,_,_,_,_,m,m,m,m,_,_,_,_,_,_,L,L,L,_}, // 12
{_,_,X,X,_,_,_,_,x,x,_,x,_,X,X,_,_,_,a,_,X,_,A,A,a,_,_,_,_,_,_,A,A,A,A,_,_,_,L,_}, // 13
{_,_,_,X,X,_,_,x,x,_,_,M,_,_,X,a,a,a,a,_,X,_,_,a,a,a,a,a,a,a,a,a,A,A,A,A,_,_,L,_}, // 14
{_,m,_,_,X,X,x,x,_,_,M,M,_,_,_,a,a,a,_,_,X,X,_,_,a,_,_,a,_,_,_,_,A,A,A,A,A,_,L,_}, // 15
{_,m,m,_,_,X,X,_,_,M,M,M,_,a,_,_,_,_,_,X,X,X,X,_,_,_,a,a,_,_,E,_,_,_,_,_,_,_,L,_}, // 16
{_,m,m,m,_,_,_,_,_,_,_,M,_,a,a,a,a,X,X,X,X,X,X,X,a,a,a,_,_,E,E,l,_,_,l,l,l,_,L,_}, // 17
{_,m,m,m,_,M,M,M,_,M,M,M,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,E,E,_,l,l,_,l,_,l,_,L,_}, // 18
{_,m,_,m,m,m,_,M,M,M,M,M,_,E,E,_,e,e,e,e,e,e,E,E,E,E,E,E,E,_,_,_,l,l,l,_,l,L,L,_}, // 19
{_,m,_,_,_,_,_,_,_,_,_,_,_,e,_,_,e,e,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}, // 20
{_,m,m,m,L,L,L,_,L,l,l,l,_,e,e,e,e,e,e,e,R,R,R,R,R,R,R,R,_,_,r,r,r,_,R,R,r,r,r,_}, // 21
{_,_,_,_,_,_,L,_,_,l,l,l,_,e,_,_,_,e,e,e,R,_,e,_,_,_,_,R,R,R,r,_,r,_,r,_,_,_,U,_}, // 22
{_,L,L,_,L,L,L,L,_,_,_,l,_,_,_,l,_,_,_,e,_,_,e,e,e,e,_,_,R,R,r,_,r,_,r,U,U,_,U,_}, // 23
{_,_,L,_,_,L,_,_,_,L,_,l,l,l,l,l,l,_,e,e,e,_,_,E,_,e,e,R,R,R,r,r,r,_,_,U,U,_,U,_}, // 24
{_,_,L,L,L,L,_,l,l,l,_,_,l,_,l,_,l,_,e,e,e,_,_,_,_,_,_,_,_,_,_,_,r,r,_,_,U,U,U,_}, // 25
{_,l,L,_,_,_,_,l,l,l,l,_,l,l,l,l,l,_,_,e,_,_,c,c,c,_,C,C,C,r,r,_,_,r,r,r,r,_,U,_}, // 26
{_,l,_,_,l,l,_,_,_,l,_,_,l,_,l,l,_,_,e,e,_,_,_,c,c,C,C,C,C,_,r,r,_,_,_,_,_,_,U,_}, // 27
{_,l,_,_,l,l,l,l,l,l,l,l,l,l,l,_,_,e,e,_,_,M,_,_,C,C,C,C,C,u,u,u,u,u,u,u,u,u,u,_}, // 28
{_,l,l,_,_,_,_,_,_,l,_,E,l,l,_,_,E,e,_,_,M,M,x,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}, // 29
{_,l,l,l,l,l,l,l,l,l,E,E,E,_,_,E,E,_,_,M,M,_,x,x,_,_,A,A,_,_,a,a,a,a,a,a,a,a,a,_}, // 30
{_,l,_,_,_,_,_,_,_,l,_,E,_,_,E,E,_,_,M,M,_,_,_,x,x,_,_,A,A,A,a,a,_,_,_,_,_,_,a,_}, // 31
{_,l,_,l,l,l,l,l,_,l,_,E,E,E,E,_,_,M,M,_,_,_,_,_,x,x,_,_,A,A,A,_,_,a,a,a,a,a,a,_}, // 32
{_,l,_,l,l,l,l,l,_,l,_,_,_,_,_,_,M,M,_,_,M,_,M,_,_,x,x,_,_,A,A,_,_,a,_,_,_,_,X,_}, // 33
{_,l,_,l,_,_,_,l,l,l,l,l,l,_,_,m,M,_,_,M,M,M,M,M,_,_,x,x,_,_,A,A,_,a,_,A,A,_,X,_}, // 34
{_,L,_,L,L,_,l,l,l,_,_,l,_,_,m,m,M,M,M,M,_,x,_,M,M,M,M,x,x,_,_,A,_,a,_,_,A,_,X,_}, // 35
{_,L,_,L,L,_,l,l,_,_,_,_,_,m,m,_,M,M,_,M,x,x,x,M,_,M,M,_,x,x,_,_,_,a,a,a,A,_,X,_}, // 36
{_,L,_,_,_,_,_,_,_,m,m,_,m,m,_,_,M,M,M,M,_,x,_,M,M,M,M,_,_,x,x,_,_,_,_,_,_,_,X,_}, // 37
{_,L,L,L,L,L,L,L,L,m,m,m,m,_,_,_,M,_,_,M,M,M,M,M,_,_,M,_,_,_,x,x,x,x,X,X,X,X,X,_}, // 38
{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}, // 39
*/
/*
{_,_,_,_,_,_,s,s,_,_,_,s,s,s,s,s,s,s,_,_,s,s,s,s,s,s,_,_,_,s,s,s,_,_,T,T,T,_,_,_}, // 0
{_,_,_,X,X,_,_,s,s,s,s,s,_,_,_,_,_,S,S,S,S,_,_,_,_,s,s,s,s,s,s,_,_,T,T,T,T,T,_,_}, // 1
{_,_,X,X,X,X,_,_,_,_,T,T,T,T,T,_,_,_,S,S,_,_,T,T,T,T,s,_,_,_,_,_,_,t,_,s,_,t,_,_}, // 2
{_,X,X,X,X,X,X,X,X,_,_,_,_,T,T,T,T,_,_,_,_,T,T,T,_,_,_,_,_,A,A,_,_,t,_,_,_,t,_,_}, // 3
{_,X,_,X,_,_,_,_,X,X,X,_,_,_,_,_,T,T,_,_,T,T,_,_,_,_,A,A,A,A,_,_,_,t,t,t,t,t,t,_}, // 4
{_,_,_,X,_,a,a,a,a,a,a,_,_,_,_,_,_,t,_,t,t,_,_,A,A,A,A,_,_,A,A,A,_,_,_,t,_,_,t,_}, // 5
{_,X,X,X,_,a,a,_,_,_,_,_,A,A,A,A,t,t,t,t,_,_,A,A,_,_,_,_,_,_,A,A,_,A,A,A,A,_,A,_}, // 6
{_,X,X,_,_,_,_,_,A,A,A,A,A,_,_,_,_,t,t,t,t,A,A,_,_,a,a,a,a,_,_,A,A,A,A,A,A,A,A,_}, // 7
{_,X,X,_,_,a,a,a,a,A,_,_,_,_,_,A,t,t,t,t,_,_,_,_,a,a,a,a,a,a,_,_,A,A,A,_,_,A,_,_}, // 8
{_,X,X,_,a,a,_,_,_,_,_,a,a,_,_,A,_,t,_,t,A,A,A,_,_,_,_,_,a,a,_,_,a,a,_,_,_,a,a,_}, // 9
{_,X,X,_,_,a,_,_,a,a,a,a,a,_,A,A,_,A,_,_,_,_,A,A,A,A,A,_,a,_,_,_,a,_,_,_,_,_,a,_}, // 10
{_,X,X,_,_,a,_,_,a,a,a,_,_,_,A,_,_,A,A,A,_,_,_,_,_,_,A,a,a,a,a,a,a,a,_,_,_,_,a,_}, // 11
{_,X,X,_,_,a,a,_,_,X,_,_,_,a,A,_,_,_,A,A,A,A,A,_,_,_,_,_,_,_,_,_,_,a,a,a,a,a,a,_}, // 12
{_,X,X,_,_,_,a,_,_,X,X,_,_,a,_,_,a,_,_,_,_,_,A,A,A,_,_,_,_,_,_,_,_,_,_,X,_,_,_,_}, // 13
{_,X,_,_,_,_,X,X,_,_,X,_,_,a,_,a,a,a,a,_,_,_,_,_,A,A,_,_,_,_,_,X,X,X,_,X,_,_,_,_}, // 14
{_,X,X,X,X,X,X,X,X,X,X,_,_,a,a,a,_,a,a,a,a,a,_,_,_,A,A,_,_,_,X,X,_,X,X,X,_,_,_,_}, // 15
{_,X,_,_,_,_,X,_,X,X,_,_,_,_,a,_,_,a,a,_,_,a,a,a,_,_,_,_,_,_,X,X,_,_,_,X,_,_,_,_}, // 16
{_,x,x,x,x,x,x,_,_,_,_,_,_,_,X,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,X,X,X,X,X,X,X,X,_}, // 17
{_,x,_,_,x,x,_,_,_,x,x,_,_,_,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,_,_,_,_,_,a,_}, // 18
{_,_,_,x,x,x,_,_,x,x,x,x,x,X,X,X,X,X,_,_,_,_,_,_,_,_,X,_,X,_,X,_,X,_,a,a,a,a,a,_}, // 19
{_,_,_,x,x,_,_,x,x,x,_,x,_,X,X,X,_,_,_,m,m,m,_,_,_,_,X,X,X,X,X,X,X,_,a,a,_,_,_,_}, // 20
{_,_,_,_,x,_,_,x,_,_,_,_,_,X,_,_,_,m,m,m,m,m,m,m,L,_,_,_,X,X,X,_,_,_,a,_,_,_,_,_}, // 21
{_,_,_,_,x,x,x,x,M,M,M,_,_,_,_,m,m,m,_,_,_,_,_,_,L,L,L,_,_,_,_,_,_,_,_,_,l,_,_,_}, // 22
{_,_,_,x,x,_,_,_,M,M,M,M,_,_,m,m,m,_,_,_,m,m,m,_,_,_,L,L,_,_,l,l,_,_,l,_,l,l,_,_}, // 23
{_,_,_,x,_,_,_,_,_,M,M,M,_,m,m,m,_,_,m,_,_,m,m,L,L,_,_,L,_,l,l,l,l,l,l,_,l,l,l,_}, // 24
{_,_,_,x,x,_,M,M,_,_,M,_,_,m,m,_,_,m,m,m,_,m,m,L,L,L,_,L,_,l,l,l,_,l,l,_,l,l,l,_}, // 25
{_,_,x,x,M,M,M,M,M,_,M,_,m,m,_,_,m,m,m,m,m,m,_,L,L,L,_,L,_,_,l,l,_,l,l,l,l,l,_,_}, // 26
{_,x,x,x,_,_,_,_,M,M,M,M,m,m,_,m,m,_,_,m,m,_,_,L,L,L,L,L,_,_,_,l,_,_,l,l,l,l,_,_}, // 27
{x,x,_,_,_,_,_,_,_,M,_,_,_,m,_,_,m,_,m,m,m,_,L,L,_,_,L,L,l,_,_,l,_,_,_,E,E,E,_,_}, // 28
{x,x,_,X,X,X,X,X,_,M,M,M,_,m,m,_,_,_,_,m,m,_,_,_,_,L,L,L,l,l,l,l,l,l,_,E,E,_,_,_}, // 29
{x,x,_,_,_,x,x,X,_,_,M,M,_,_,m,m,m,m,_,_,_,_,L,L,L,L,_,_,_,_,_,_,_,l,_,_,E,_,_,_}, // 30
{x,x,x,_,x,x,x,X,_,_,_,_,_,_,_,_,_,m,m,m,L,L,L,_,_,_,_,e,e,_,_,_,_,_,_,E,E,E,_,_}, // 31
{_,x,x,x,x,x,_,X,_,_,_,u,U,_,_,_,_,_,_,_,_,_,_,_,_,R,R,e,e,e,e,e,E,E,E,E,E,E,_,_}, // 32
{_,_,x,x,x,_,_,X,_,_,u,u,U,U,U,U,_,_,_,_,_,_,_,_,R,R,R,e,e,e,e,e,_,_,_,_,E,_,_,l}, // 33
{_,_,_,x,_,_,_,_,_,u,u,u,_,U,U,U,U,U,r,r,_,_,_,R,R,R,_,e,e,e,_,_,_,_,_,_,E,_,l,l}, // 34
{_,_,_,_,_,_,_,_,u,u,r,r,_,_,U,U,_,r,r,r,r,r,_,r,R,R,_,_,e,e,_,l,l,l,l,_,E,_,l,l}, // 35
{_,_,_,_,_,_,C,C,u,_,r,r,R,_,U,U,_,_,_,_,r,r,r,r,R,R,R,e,e,_,_,l,_,_,l,_,E,_,l,l}, // 36
{_,_,_,c,c,c,C,C,C,_,_,_,_,_,U,U,U,_,_,_,_,r,r,r,_,R,R,e,e,_,_,l,l,_,_,_,E,_,E,E}, // 37
{_,_,c,c,c,_,_,C,C,U,U,U,U,U,U,_,e,e,e,e,e,e,_,_,_,_,_,e,e,e,_,_,E,E,E,E,E,E,E,E}, // 38
{_,_,_,_,_,_,_,_,_,U,U,U,U,_,_,_,_,_,e,_,e,e,E,E,_,_,e,e,_,e,E,_,_,_,_,_,_,_,_,_}, // 39
*/
/*
{A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,_,_,_,_,_,_,_,_,U,u,u,u,u,u,C,C,C,_,_,c,c,c}, // 0
{A,_,_,A,A,A,A,A,A,A,A,A,A,A,A,A,_,_,_,r,r,r,r,r,U,_,U,u,u,u,u,u,_,C,C,_,c,c,c,c}, // 1
{A,A,_,_,_,A,A,A,A,A,A,A,A,A,A,_,_,r,r,r,r,r,r,r,U,U,U,_,_,u,u,_,_,C,C,C,c,c,c,c}, // 2
{A,A,A,A,_,_,_,_,A,A,A,_,A,A,_,_,r,r,r,r,r,r,r,r,U,U,U,U,_,_,_,_,u,C,C,C,c,c,_,_}, // 3
{A,A,A,A,A,A,A,A,A,A,_,_,A,A,_,r,r,_,_,_,r,r,r,r,U,_,U,U,u,_,u,u,u,C,C,C,_,_,_,e}, // 4
{A,A,A,A,A,A,A,A,A,A,_,A,A,A,_,e,e,e,e,_,_,r,r,r,_,_,U,U,u,u,u,u,u,C,_,_,_,e,e,e}, // 5
{A,A,A,A,A,A,A,A,A,_,_,A,A,A,_,e,e,e,e,E,_,_,r,r,R,_,_,U,u,u,u,u,_,_,_,e,e,e,e,e}, // 6
{A,A,A,A,A,A,A,_,_,_,A,A,A,A,_,_,E,e,e,e,e,_,R,R,R,R,_,_,u,u,_,_,_,e,e,e,e,e,e,e}, // 7
{a,a,a,a,A,A,_,_,A,A,A,A,A,A,A,_,_,e,e,e,e,_,_,R,R,R,R,_,_,_,_,e,e,e,e,e,e,e,e,e}, // 8
{a,a,a,a,_,_,_,A,A,A,A,A,A,A,A,A,_,_,R,R,R,R,R,R,R,R,R,e,e,e,e,e,e,_,_,e,e,e,e,e}, // 9
{a,a,a,a,a,a,a,a,A,A,A,A,A,A,t,t,t,_,_,_,R,R,R,R,R,R,R,e,e,e,e,e,e,e,_,_,e,e,_,e}, // 10
{a,a,a,a,a,a,a,a,A,A,A,A,A,t,t,t,t,t,t,_,_,_,R,R,R,R,_,e,e,e,e,e,e,e,e,_,_,_,_,e}, // 11
{a,a,a,a,a,a,a,a,a,_,_,A,A,t,t,t,t,t,t,t,t,_,_,_,_,_,_,e,e,e,e,e,E,E,E,E,E,E,E,E}, // 12
{a,_,_,_,a,a,a,a,a,a,_,A,t,t,t,t,t,t,t,t,t,t,t,t,t,t,_,_,e,e,e,E,E,E,E,E,E,E,E,E}, // 13
{a,a,a,_,_,a,a,a,a,a,_,A,t,t,t,t,t,t,t,t,_,_,_,_,t,T,T,_,_,_,e,E,E,E,E,E,E,E,E,E}, // 14
{a,a,a,a,_,a,a,a,a,a,_,_,t,t,t,t,_,_,_,_,_,s,s,_,_,T,T,T,T,_,_,E,E,E,E,E,E,E,E,E}, // 15
{a,a,a,a,_,_,a,a,a,a,a,_,t,t,_,_,_,s,s,s,s,s,s,s,_,T,T,T,T,T,_,_,E,E,E,l,l,l,l,l}, // 16
{a,a,a,a,_,_,a,a,a,a,a,_,_,t,_,s,s,s,s,_,_,_,_,s,_,_,T,T,T,T,T,_,_,l,l,l,l,l,l,l}, // 17
{a,a,a,a,a,_,_,a,a,a,a,a,_,_,_,s,s,_,_,_,S,S,_,s,s,_,T,T,T,T,T,_,_,_,l,l,l,l,l,l}, // 18
{X,X,_,a,a,a,_,a,a,a,a,a,_,_,s,s,_,_,S,S,S,S,_,_,s,_,T,T,T,_,_,_,l,l,l,l,l,l,l,l}, // 19
{X,X,_,a,a,a,_,X,X,X,X,X,_,s,s,_,_,S,S,_,_,S,S,_,s,_,T,T,_,_,l,l,l,l,l,_,_,_,l,l}, // 20
{X,X,_,_,a,a,_,X,X,X,X,X,_,s,s,_,S,S,_,_,S,S,_,_,s,_,T,T,_,l,l,l,l,l,l,l,l,_,_,l}, // 21
{X,X,_,a,a,a,_,_,X,X,X,X,_,s,_,_,S,S,S,S,S,_,_,s,s,_,T,_,_,l,l,l,l,l,l,l,l,l,_,_}, // 22
{X,_,_,a,a,a,_,_,X,X,X,_,_,s,_,s,s,_,S,_,_,_,s,s,_,_,T,_,l,l,l,l,l,l,l,l,l,l,l,l}, // 23
{X,_,_,a,a,_,_,X,X,X,X,_,s,s,_,s,s,_,_,_,s,s,s,_,_,T,T,_,l,l,l,l,l,l,l,l,l,l,l,l}, // 24
{X,X,_,_,_,_,X,X,X,X,X,_,s,_,_,s,s,s,s,s,s,_,_,_,s,s,_,_,l,l,l,l,l,l,l,l,l,l,l,l}, // 25
{X,X,X,X,X,X,X,X,X,X,_,_,s,_,s,s,s,_,_,_,_,_,s,s,s,_,_,l,l,l,l,_,_,_,l,l,l,l,l,l}, // 26
{X,X,X,X,X,X,X,X,X,X,_,s,s,_,s,_,_,_,s,s,s,s,s,s,s,_,L,L,L,L,_,_,l,l,l,l,l,l,l,l}, // 27
{X,X,X,X,X,X,X,X,_,X,_,s,s,_,_,_,s,s,s,s,s,s,s,s,_,_,L,L,L,_,_,l,l,l,l,l,l,_,L,L}, // 28
{X,X,_,_,X,X,X,_,_,X,_,_,s,s,s,s,s,_,_,_,_,_,_,_,_,L,L,L,L,_,l,l,l,l,l,l,_,_,L,L}, // 29
{X,_,_,x,x,x,x,_,X,X,X,_,s,s,_,_,_,_,M,M,M,M,M,M,_,L,L,L,L,_,_,l,l,l,l,l,_,L,L,L}, // 30
{X,_,x,x,x,x,x,_,X,X,X,_,_,_,_,M,M,M,M,M,M,M,M,M,_,_,L,L,L,L,L,L,L,L,L,_,_,L,L,L}, // 31
{X,_,x,x,x,x,_,_,_,_,_,_,M,M,M,M,M,M,M,M,M,M,M,M,M,_,_,L,L,L,L,L,L,_,_,_,L,L,L,L}, // 32
{_,_,_,_,x,x,x,x,x,x,x,M,M,M,M,M,_,_,_,_,_,_,_,M,M,M,_,L,L,L,L,_,_,_,L,L,L,L,L,L}, // 33
{x,x,x,x,x,x,x,x,x,x,x,M,M,M,M,_,_,M,M,M,M,M,_,_,_,M,_,_,m,m,m,m,m,m,m,m,m,m,m,m}, // 34
{x,x,x,x,x,x,x,x,x,x,_,_,_,_,_,_,M,M,M,M,M,M,M,M,_,m,m,_,_,m,m,m,m,m,_,_,_,m,m,m}, // 35
{x,x,x,x,x,_,_,_,_,_,_,M,M,M,M,M,M,M,M,M,M,M,M,M,_,_,m,m,_,m,m,m,m,_,_,m,m,m,m,m}, // 36
{x,x,x,_,_,_,M,M,M,M,M,M,M,M,M,M,_,_,_,_,_,_,M,m,m,_,_,m,_,_,m,m,m,_,m,m,m,m,m,m}, // 37
{x,x,x,M,M,M,M,M,M,M,M,M,M,_,_,_,_,m,m,m,m,_,_,m,m,m,m,m,m,_,m,m,m,_,_,m,m,m,m,m}, // 38
{x,x,x,M,M,M,M,M,M,M,M,_,_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m}, // 39
*/
{c,c,C,C,_,u,u,u,u,u,u,_,_,_,r,_,_,_,_,_,e,_,_,_,_,L,L,L,_,l,l,_,_,_,L,L,L,L,L,L}, // 0
{c,c,C,C,_,u,u,_,U,_,u,u,u,_,r,_,r,r,r,_,e,e,e,_,_,_,L,_,_,_,l,l,l,_,L,L,L,L,L,L}, // 1
{_,_,C,u,u,u,_,_,U,_,_,_,u,_,r,r,r,_,R,R,R,_,e,e,e,_,l,l,_,l,l,_,l,l,l,L,L,L,L,L}, // 2
{U,_,_,u,_,_,_,r,U,r,r,_,U,_,_,U,_,_,_,R,_,_,_,_,e,_,_,l,l,l,_,_,_,l,l,L,L,L,L,m}, // 3
{u,u,u,u,U,_,r,r,_,_,r,_,U,U,U,U,_,_,_,R,R,_,_,e,e,e,_,_,_,l,l,_,l,l,_,L,L,L,m,m}, // 4
{_,_,_,_,U,U,r,_,_,_,r,_,_,_,U,_,_,_,_,_,R,R,_,e,e,_,_,l,_,_,l,l,l,_,_,L,L,m,m,m}, // 5
{R,_,U,U,U,_,r,r,_,_,r,r,_,_,U,r,r,_,r,r,R,_,_,e,_,_,_,l,l,l,l,_,_,_,_,_,m,m,m,m}, // 6
{R,_,_,_,_,_,_,r,_,_,_,r,R,_,U,_,r,r,r,_,_,_,e,e,_,_,l,l,l,l,_,_,M,_,M,_,_,m,m,m}, // 7
{R,R,R,R,_,R,R,R,_,_,_,_,R,_,_,_,_,_,r,R,_,e,e,_,_,_,E,_,_,_,_,M,M,_,M,M,_,m,m,m}, // 8
{R,R,R,R,R,R,_,R,_,_,_,R,R,_,M,M,M,_,_,_,_,e,E,_,_,E,E,_,x,x,x,M,M,_,_,M,_,_,m,m}, // 9
{e,e,_,_,_,_,_,e,e,_,e,e,_,_,M,M,M,M,x,x,_,_,E,E,_,E,_,_,_,x,x,_,M,M,M,M,M,_,m,m}, // 10
{e,e,e,e,e,e,_,_,e,e,e,_,_,M,M,_,_,M,x,x,x,_,_,E,E,E,_,E,_,_,x,_,_,_,_,M,M,_,m,m}, // 11
{e,e,e,e,_,e,e,_,_,_,_,_,_,M,M,M,_,M,M,x,x,x,_,_,E,E,E,E,E,_,x,x,_,_,M,M,M,m,m,m}, // 12
{_,_,_,e,_,_,e,E,E,_,l,l,_,_,M,M,M,M,M,x,x,x,x,_,_,E,_,l,l,_,x,x,_,_,M,M,M,m,m,m}, // 13
{_,l,_,e,e,e,E,E,E,_,_,l,l,_,M,M,M,M,_,_,x,x,x,x,_,_,_,l,l,_,x,x,_,M,M,M,M,M,m,m}, // 14
{l,l,_,_,_,E,E,E,E,E,l,l,l,_,M,M,M,_,_,_,_,x,x,x,_,X,_,_,l,_,x,x,x,x,_,_,M,M,M,_}, // 15
{l,l,l,l,_,_,_,_,_,_,l,l,_,_,M,M,M,_,x,x,_,_,x,x,_,X,X,_,_,_,x,x,x,x,x,_,_,M,M,_}, // 16
{l,l,l,l,l,_,l,l,l,l,l,l,_,m,m,_,_,_,x,x,x,_,_,x,_,_,X,X,X,_,X,X,x,x,x,X,_,M,M,_}, // 17
{l,_,_,l,l,_,l,l,l,l,l,_,_,m,_,_,m,_,M,x,x,_,_,x,x,_,X,_,X,_,_,X,X,X,X,X,_,_,_,_}, // 18
{l,_,l,l,l,l,l,_,_,_,_,_,m,m,_,m,m,_,M,M,x,x,_,_,X,X,X,_,X,X,X,X,X,X,X,X,X,X,X,X}, // 19
{_,_,l,l,_,_,_,_,L,L,L,m,m,m,_,m,m,_,M,M,M,x,x,_,X,_,_,_,_,X,X,X,X,X,X,X,X,_,_,X}, // 20
{_,l,l,l,_,l,L,L,L,L,_,_,m,m,m,m,m,M,M,M,_,x,x,_,X,X,X,_,_,_,X,X,_,_,X,_,_,_,X,X}, // 21
{_,l,l,l,l,l,L,L,L,_,_,m,m,m,m,m,m,M,M,_,_,x,x,_,_,_,X,X,X,X,X,X,X,_,X,X,X,X,X,_}, // 22
{_,_,_,_,l,l,L,L,L,L,L,m,m,m,_,m,m,M,M,_,_,x,_,_,_,_,_,X,X,_,_,a,a,_,X,X,_,_,_,_}, // 23
{_,_,s,_,_,_,_,_,_,_,L,m,m,m,_,_,m,m,m,_,_,_,_,a,a,a,_,_,_,_,a,a,a,_,a,_,_,_,_,_}, // 24
{s,_,s,_,T,T,T,T,T,_,_,m,m,m,m,_,_,m,m,_,a,a,a,a,_,_,_,a,a,a,a,a,_,_,a,_,_,_,_,_}, // 25
{s,_,s,T,T,_,_,_,T,T,_,_,m,m,m,m,m,m,_,_,a,_,_,a,a,a,a,a,a,a,_,_,_,a,a,_,_,_,_,_}, // 26
{s,_,s,_,T,_,_,_,_,T,T,_,_,_,m,m,m,_,_,a,a,a,a,a,_,_,_,_,_,_,_,a,a,a,a,a,_,_,_,_}, // 27
{s,_,_,_,T,T,_,_,_,_,T,T,_,_,_,_,_,_,a,a,a,_,_,_,_,s,s,T,_,a,a,a,a,_,_,a,_,_,_,A}, // 28
{s,s,s,T,T,T,T,_,_,_,T,T,_,A,A,A,_,A,A,A,_,_,s,s,_,_,_,T,_,_,a,a,_,_,a,a,a,_,A,A}, // 29
{s,s,s,T,T,T,T,T,T,T,T,_,_,A,_,A,A,A,_,A,_,s,s,s,T,T,T,T,T,_,_,A,_,a,a,_,a,A,A,_}, // 30
{s,s,_,_,_,_,_,_,_,T,T,_,A,A,_,_,_,_,_,A,_,s,s,_,_,_,_,_,T,T,_,A,_,A,_,_,_,A,_,_}, // 31
{s,_,_,S,S,S,S,S,_,_,T,_,A,_,_,_,_,_,A,A,_,s,_,_,S,S,S,_,_,T,_,_,_,A,A,_,_,A,A,_}, // 32
{s,_,S,S,_,_,_,S,S,_,T,_,A,A,A,_,_,_,A,_,_,s,s,S,S,_,S,S,_,T,T,t,_,_,_,_,_,_,A,A}, // 33
{s,_,S,_,_,_,_,_,S,_,T,_,_,_,A,A,A,A,A,A,_,s,_,S,_,_,_,S,_,T,_,t,_,_,_,_,A,A,A,_}, // 34
{s,_,S,S,_,_,_,S,S,_,t,t,t,_,_,_,_,_,_,A,_,_,_,S,_,_,_,S,_,t,_,t,t,t,A,A,A,_,_,_}, // 35
{s,_,_,S,S,_,S,S,_,_,t,_,t,t,t,t,t,t,_,A,A,A,_,S,_,_,_,S,_,t,_,_,_,t,A,_,_,_,_,_}, // 36
{s,s,_,_,S,S,S,_,_,t,t,_,_,t,_,_,_,t,A,A,_,A,_,S,S,_,S,S,_,t,t,t,_,t,_,_,_,_,_,_}, // 37
{s,s,s,_,_,s,_,_,T,t,t,t,_,t,t,t,_,_,_,A,_,A,_,_,S,S,S,_,_,t,_,t,_,t,t,_,_,_,_,T}, // 38
{s,s,s,s,s,s,_,T,T,t,t,t,t,t,t,t,t,t,A,A,A,A,A,_,_,_,_,_,t,t,_,t,t,t,t,t,t,t,t,t}, // 39
};
// clang-format on
RR_DEFINE_MAZE(BURROW, 4) = {{1, 1}, {0, 1}};

#define MAZE_ENTRY(MAZE, GRID_SIZE)                                            \
    (sizeof(RR_MAZE_##MAZE[0]) / sizeof(struct rr_maze_grid)), GRID_SIZE,      \
        &RR_MAZE_##MAZE[0][0]

struct rr_maze_declaration RR_MAZES[rr_biome_id_max] = {
    {MAZE_ENTRY(HELL_CREEK, 1024), 8 + 7, {
        // {-2, -2, 43, 43, 3, 31, 1}, // pvp

        // hell creek

        {0, 0, 4, 2, 1, 0, 1},   // 0
        {4, 4, 2, 2, 4, 5, 20},  // 1
        {3, 8, 3, 2, 4, 9, 40},  // 2
        {2, 11, 2, 2, 2, 12, 60},  // 3
        {9, 16, 3, 2, 10, 16, 80},  // 4
        {6, 21, 3, 3, 7, 22, 100},  // 5
        {13,17, 2, 2, 13, 17, 120}, // 6
        {20,12, 2, 3, 20, 13, 140}, // 7

        // garden

        {13, 4, 3, 2, 14, 4, 20},  // 0
        {18, 1, 2, 3, 18, 2, 40}, // 1
        {23, 4, 3, 2, 24, 4, 60}, // 2
        {25, 8, 2, 2, 26, 9, 80}, // 3
        {33, 2, 3, 2, 34, 3, 100}, // 4
        {37,11, 3, 3, 38, 12, 120}, // 5
        {32,14, 2, 2, 33, 15, 140} // 6

    }},
    {MAZE_ENTRY(HELL_CREEK, 1024), 0},
    {MAZE_ENTRY(BURROW, 512), 0},
};

uint8_t RR_GLOBAL_BIOME = rr_biome_id_hell_creek;
#undef _
#undef c
#undef C
#undef u
#undef U
#undef r
#undef R
#undef e
#undef E
#undef l
#undef L
#undef m
#undef M
#undef x
#undef X
#undef a
#undef A
#undef t
#undef T
#undef s
#undef S