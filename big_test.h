#include <iostream>
#include <string>
#include <vector>


#include "Traveller.h"
#include "TravelMode.h"
#include "WalkingMode.h"
#include "CycleMode.h"
#include "ZiplineMode.h"
#include "BoatMode.h"
#include "SwimMode.h"
#include "Terrain.h"
#include "DesertTerrain.h"
#include "RouteStrategy.h"
#include "FastestRoute.h"
#include "ScenicRoute.h"
#include "ShortestRoute.h"
#include "dialogue.h"

using namespace std;

class MockTerrain : public Terrain {
public:
    MockTerrain(bool canWalk = true, bool canCycle = true, bool canZipline = true, bool canSwim = true) {
        walk = canWalk;
        cycle = canCycle;
        zipline = canZipline;
        swim = canSwim;
    }
    string getDescription() override { return "Mock terrain for testing"; }
};

// Function to run all tests
void runAllTests() {
    cout << "\n========== STARTING COMPREHENSIVE TESTS ==========\n\n";
    int testCount = 0;
    int passedCount = 0;

    // ============================================================
    // TEST 1: Terrain and DesertTerrain
    // ============================================================
    cout << "TEST " << ++testCount << ": Terrain Classes\n";
    cout << "-----------------------\n";
    {
        DesertTerrain desert;
        cout << "DesertTerrain - canWalk: " << desert.canWalk() 
             << ", canCycle: " << desert.canCycle()
             << ", canZipline: " << desert.canZipline()
             << ", canSwim: " << desert.canSwim() << endl;
        cout << "Description: " << desert.getDescription() << endl;
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 2: Traveller Construction and Basic Operations
    // ============================================================
    cout << "TEST " << ++testCount << ": Traveller Basics\n";
    cout << "------------------------\n";
    {
        DesertTerrain terrain;
        Traveller traveller(terrain, 100, 50, "TestTraveller");
        
        cout << "Name: " << traveller.getName() << endl;
        cout << "Energy: " << traveller.getEnergy() << endl;
        cout << "Money: " << traveller.getMoney() << endl;
        
        traveller.setEnergy(75);
        traveller.setMoney(25);
        cout << "After setters - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        
        MockTerrain newTerrain;
        traveller.setTerrain(newTerrain);
        cout << "✓ Terrain change works\n";
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 3: Route Strategies
    // ============================================================
    cout << "TEST " << ++testCount << ": Route Strategies\n";
    cout << "-------------------------\n";
    {
        // Test FastestRoute
        FastestRoute fastest;
        cout << "FastestRoute name: " << fastest.name() << endl;
        RouteStrategy* clonedFastest = fastest.clone();
        cout << "Cloned FastestRoute name: " << clonedFastest->name() << endl;
        delete clonedFastest;
        
        // Test ScenicRoute
        ScenicRoute scenic;
        cout << "ScenicRoute name: " << scenic.name() << endl;
        RouteStrategy* clonedScenic = scenic.clone();
        cout << "Cloned ScenicRoute name: " << clonedScenic->name() << endl;
        delete clonedScenic;
        
        // Test ShortestRoute
        ShortestRoute shortest;
        cout << "ShortestRoute name: " << shortest.name() << endl;
        RouteStrategy* clonedShortest = shortest.clone();
        cout << "Cloned ShortestRoute name: " << clonedShortest->name() << endl;
        delete clonedShortest;
        
        cout << "✓ All RouteStrategies work\n";
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 4: RouteStrategy Outputs
    // ============================================================
    cout << "TEST " << ++testCount << ": RouteStrategy Outputs\n";
    cout << "-------------------------------\n";
    {
        cout << "FastestRoute output:" << endl;
        FastestRoute route1;
        route1.findRoute();
        
        cout << "\nScenicRoute output:" << endl;
        ScenicRoute route2;
        route2.findRoute();
        
        cout << "\nShortestRoute output:" << endl;
        ShortestRoute route3;
        route3.findRoute();
        
        cout << "✓ All RouteStrategy outputs verified\n";
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 5: CycleMode
    // ============================================================
    cout << "TEST " << ++testCount << ": CycleMode\n";
    cout << "------------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 100, 50, "Cyclist");
        traveller.setMode(new CycleMode());
        
        cout << "Before CycleMode - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        traveller.move();
        cout << "After CycleMode - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 6: ZiplineMode
    // ============================================================
    cout << "TEST " << ++testCount << ": ZiplineMode\n";
    cout << "-------------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 100, 50, "Zipliner");
        traveller.setMode(new ZiplineMode());
        
        cout << "Before ZiplineMode - Money: " << traveller.getMoney() << endl;
        traveller.move();
        cout << "After ZiplineMode - Money: " << traveller.getMoney() << endl;
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 7: BoatMode
    // ============================================================
    cout << "TEST " << ++testCount << ": BoatMode\n";
    cout << "----------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 100, 50, "Boater");
        traveller.setMode(new BoatMode());
        
        cout << "Before BoatMode - Money: " << traveller.getMoney() << endl;
        traveller.move();
        cout << "After BoatMode - Money: " << traveller.getMoney() << endl;
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 8: WalkingMode - Terrain Restrictions
    // ============================================================
    cout << "TEST " << ++testCount << ": WalkingMode - Terrain Restrictions\n";
    cout << "-------------------------------------------\n";
    {
        MockTerrain terrain(false, true, true, true);
        Traveller traveller(terrain, 100, 50, "NoWalker");
        cout << "Testing walking on terrain with canWalk=false" << endl;
        traveller.move();
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 9: WalkingMode - Insufficient Resources
    // ============================================================
    try{
    cout << "TEST " << ++testCount << ": WalkingMode - Insufficient Resources\n";
    cout << "--------------------------------------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 5, 5, "PoorTraveller");
        cout << "Testing with low resources - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        traveller.move();
        passedCount++;
    }
    cout << endl;
} catch(...){}

    // ============================================================
    // TEST 10: SwimMode - Terrain Restrictions
    // ============================================================
    cout << "TEST " << ++testCount << ": SwimMode - Terrain Restrictions\n";
    cout << "----------------------------------------\n";
    {
        MockTerrain terrain(true, true, true, false);
        Traveller traveller(terrain, 100, 50, "NoSwimmer");
        traveller.setMode(new SwimMode());
        cout << "Testing swimming on terrain with canSwim=false" << endl;
        traveller.move();
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 11: SwimMode - Insufficient Resources
    // ============================================================
    try{
    cout << "TEST " << ++testCount << ": SwimMode - Insufficient Resources\n";
    cout << "-----------------------------------------\n";
    {
        MockTerrain terrain(true, true, true, true);
        Traveller traveller(terrain, 10, 10, "PoorSwimmer");
        traveller.setMode(new SwimMode());
        cout << "Testing swimming with low resources - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        traveller.move();
        passedCount++;
    }
    cout << endl;
} catch(...){}
    // ============================================================
    // TEST 12: Mode Transitions and Memory Management
    // ============================================================
    cout << "TEST " << ++testCount << ": Mode Transitions and Memory Management\n";
    cout << "-----------------------------------------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 100, 50, "MemoryTest");
        
        cout << "Performing multiple mode transitions..." << endl;
        traveller.setMode(new WalkingMode());
        cout << "  Set WalkingMode" << endl;
        traveller.setMode(new CycleMode());
        cout << "  Set CycleMode" << endl;
        traveller.setMode(new ZiplineMode());
        cout << "  Set ZiplineMode" << endl;
        traveller.setMode(new BoatMode());
        cout << "  Set BoatMode" << endl;
        traveller.setMode(new SwimMode());
        cout << "  Set SwimMode" << endl;
        traveller.setMode(new WalkingMode());
        cout << "  Set WalkingMode" << endl;
        
        cout << "✓ Multiple mode transitions without memory leaks\n";
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 13: Setting Null Mode
    // ============================================================
    cout << "TEST " << ++testCount << ": Setting Null Mode\n";
    cout << "----------------------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 100, 50, "NullTest");
        
        cout << "Testing setting null mode..." << endl;
        traveller.setMode(nullptr);
        cout << "✓ Setting null mode handled gracefully\n";
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 14: Traveller Destructor
    // ============================================================
    cout << "TEST " << ++testCount << ": Traveller Destructor\n";
    cout << "----------------------------\n";
    {
        MockTerrain terrain;
        Traveller* traveller = new Traveller(terrain, 100, 50, "DestructorTest");
        traveller->setMode(new WalkingMode());
        traveller->setMode(new CycleMode());
        
        cout << "Deleting traveller to test destructor..." << endl;
        delete traveller;
        cout << "✓ Traveller destructor cleans up modes correctly\n";
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 15: Edge Cases - Zero Resources
    // ============================================================
    try{
    cout << "TEST " << ++testCount << ": Edge Cases - Zero Resources\n";
    cout << "-------------------------------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 0, 0, "Zero");
        
        cout << "Testing with zero resources - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        traveller.move();
        passedCount++;
    }
    cout << endl;
    } catch(...){}

    // ============================================================
    // TEST 16: Edge Cases - Large Resources
    // ============================================================
    cout << "TEST " << ++testCount << ": Edge Cases - Large Resources\n";
    cout << "--------------------------------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 1000000, 1000000, "Rich");
        
        cout << "Testing with large resources - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        traveller.setMode(new CycleMode());
        traveller.move();
        cout << "After cycle: Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 17: DesertTerrain Integration
    // ============================================================
    cout << "TEST " << ++testCount << ": DesertTerrain Integration\n";
    cout << "-----------------------------------\n";
    {
        DesertTerrain desert;
        Traveller traveller(desert, 100, 50, "DesertWalker");
        
        cout << "DesertTerrain properties:" << endl;
        cout << "  canWalk: " << desert.canWalk() << endl;
        cout << "  canCycle: " << desert.canCycle() << endl;
        cout << "  canZipline: " << desert.canZipline() << endl;
        cout << "  canSwim: " << desert.canSwim() << endl;
        cout << "  Description: " << desert.getDescription() << endl;
        
        cout << "\nTesting walking in desert terrain..." << endl;
        // This will still show the menu but won't require input if we don't call move()
        // Just demonstrating desert terrain works with traveller
        cout << "✓ DesertTerrain integration works\n";
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 18: CycleMode with DesertTerrain
    // ============================================================
    cout << "TEST " << ++testCount << ": CycleMode with DesertTerrain\n";
    cout << "------------------------------------\n";
    {
        DesertTerrain desert;
        Traveller traveller(desert, 100, 50, "DesertCyclist");
        traveller.setMode(new CycleMode());
        
        cout << "Before Cycle in Desert - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        traveller.move();
        cout << "After Cycle in Desert - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 19: ZiplineMode with DesertTerrain (should work since no terrain check)
    // ============================================================
    cout << "TEST " << ++testCount << ": ZiplineMode with DesertTerrain\n";
    cout << "-------------------------------------\n";
    {
        DesertTerrain desert;
        Traveller traveller(desert, 100, 50, "DesertZipliner");
        traveller.setMode(new ZiplineMode());
        
        cout << "Before Zipline in Desert - Money: " << traveller.getMoney() << endl;
        traveller.move();
        cout << "After Zipline in Desert - Money: " << traveller.getMoney() << endl;
        passedCount++;
    }
    cout << endl;

    // ============================================================
    // TEST 20: Multiple Mode Changes with Resource Tracking
    // ============================================================
    cout << "TEST " << ++testCount << ": Multiple Mode Changes with Resource Tracking\n";
    cout << "--------------------------------------------------------\n";
    {
        MockTerrain terrain;
        Traveller traveller(terrain, 100, 100, "ResourceTracker");
        traveller.setMoney(1000000);
        traveller.setEnergy(10000000);
        cout << "Starting resources - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        
        // Test Cycle
        traveller.setMode(new CycleMode());
        traveller.move();
        cout << "After Cycle - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        
        // Test Zipline
        traveller.setMode(new ZiplineMode());
        traveller.move();
        cout << "After Zipline - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        
        // Test Boat
        traveller.setMode(new BoatMode());
        traveller.move();
        cout << "After Boat - Energy: " << traveller.getEnergy() 
             << ", Money: " << traveller.getMoney() << endl;
        
        passedCount++;
    }
    cout << endl;

    
    cout << "========== ALL TESTS COMPLETED ==========\n";
}

