// #include "Traveller.h"
// #include "Terrain.h"
// #include "OceanTerrain.h"
// #include "JungleTerrain.h"
// #include "DungeonTerrain.h"
// #include "DesertTerrain.h"
// #include "CityTerrain.h"
// #include "WalkingMode.h"
// #include "CycleMode.h"
// #include "ZiplineMode.h"
// #include "SwimMode.h"
// #include "BoatMode.h"
// #include "dialogue.h"

// #include <iostream>

// void printMenu() {
//     std::cout << "\n=== State Pattern Test Harness ===\n"
//               << " 1. CityTerrain, full stats, start Walking (walk/cycle/zipline all reachable)\n"
//               << " 2. CityTerrain, low energy + low money, start Walking (should die immediately)\n"
//               << " 3. DungeonTerrain, start Walking (cycle/zipline should be blocked)\n"
//               << " 4. OceanTerrain, start Swimming (swim only)\n"
//               << " 5. DesertTerrain, force-skip into CycleMode (test terminal state)\n"
//               << " 6. JungleTerrain, force-skip into ZiplineMode (test terminal state)\n"
//               << " 7. Custom: pick a terrain, starting mode, and stats\n"
//               << " 0. Quit\n"
//               << "Choice: ";
// }

// int readInt() {
//     int value;
//     while (!(std::cin >> value)) {
//         std::cin.clear();
//         std::cin.ignore(10000, '\n');
//         std::cout << "Invalid input, try again: ";
//     }
//     std::cin.ignore(10000, '\n');
//     return value;
// }

// void runLoop(Traveller& traveller, int turns = 3) {
//     for (int i = 0; i < turns; ++i) {
//         std::cout << "\n--- Turn " << (i + 1) << " | Energy: " << traveller.getEnergy()
//                    << " Money: " << traveller.getMoney() << " ---\n";
//         traveller.move();
//     }
// }

// int main() {
//     bool running = true;
//     while (running) {
//         printMenu();
//         int choice = readInt();

//         switch (choice) {
//             case 1: {
//                 CityTerrain terrain;
//                 std::cout << terrain.getDescription() << "\n";
//                 Traveller traveller(new WalkingMode(), terrain, 100, 100, "TestWalker");
//                 runLoop(traveller, 4);
//                 break;
//             }
//             case 2: {
//                 CityTerrain terrain;
//                 Traveller traveller(new WalkingMode(), terrain, 5, 1, "TestBroke");
//                 runLoop(traveller, 1);
//                 break;
//             }
//             case 3: {
//                 DungeonTerrain terrain;
//                 std::cout << terrain.getDescription() << "\n";
//                 Traveller traveller(new WalkingMode(), terrain, 100, 100, "TestDungeonCrawler");
//                 runLoop(traveller, 2);
//                 break;
//             }
//             case 4: {
//                 OceanTerrain terrain;
//                 std::cout << terrain.getDescription() << "\n";
//                 Traveller traveller(new SwimMode(), terrain, 100, 100, "TestSwimmer");
//                 runLoop(traveller, 2);
//                 break;
//             }
//             case 5: {
//                 DesertTerrain terrain;
//                 std::cout << terrain.getDescription() << "\n";
//                 Traveller traveller(new CycleMode(), terrain, 50, 50, "TestCyclist");
//                 runLoop(traveller, 1);
//                 break;
//             }
//             case 6: {
//                 JungleTerrain terrain;
//                 std::cout << terrain.getDescription() << "\n";
//                 Traveller traveller(new ZiplineMode(), terrain, 50, 50, "TestZipliner");
//                 runLoop(traveller, 1);
//                 break;
//             }
//             case 7: {
//                 std::cout << "Terrain (1=Ocean 2=Jungle 3=Dungeon 4=Desert 5=City): ";
//                 int terrainChoice = readInt();

//                 std::cout << "Starting energy: ";
//                 int e = readInt();
//                 std::cout << "Starting money: ";
//                 int m = readInt();
//                 std::cout << "Starting mode (1=Walking 2=Swimming 3=Cycling 4=Zipline): ";
//                 int modeChoice = readInt();

//                 TravelMode* startMode = nullptr;
//                 switch (modeChoice) {
//                     case 1: startMode = new WalkingMode(); break;
//                     case 2: startMode = new SwimMode();    break;
//                     case 3: startMode = new CycleMode();   break;
//                     case 4: startMode = new ZiplineMode(); break;
//                     default:
//                         std::cout << "Invalid mode choice, defaulting to Walking.\n";
//                         startMode = new WalkingMode();
//                 }

//                 std::cout << "How many turns to run? ";
//                 int turns = readInt();

//                 switch (terrainChoice) {
//                     case 1: { OceanTerrain t;   Traveller trav(startMode, t, e, m, "CustomTraveller"); runLoop(trav, turns); break; }
//                     case 2: { JungleTerrain t;  Traveller trav(startMode, t, e, m, "CustomTraveller"); runLoop(trav, turns); break; }
//                     case 3: { DungeonTerrain t; Traveller trav(startMode, t, e, m, "CustomTraveller"); runLoop(trav, turns); break; }
//                     case 4: { DesertTerrain t;  Traveller trav(startMode, t, e, m, "CustomTraveller"); runLoop(trav, turns); break; }
//                     case 5: { CityTerrain t;    Traveller trav(startMode, t, e, m, "CustomTraveller"); runLoop(trav, turns); break; }
//                     default:
//                         std::cout << "Invalid terrain choice.\n";
//                         delete startMode;
//                 }
//                 break;
//             }
//             case 0:
//                 running = false;
//                 break;
//             default:
//                 std::cout << "Invalid choice, try again.\n";
//         }
//     }

//     return 0;
// }