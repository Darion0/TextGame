// TextAdventure.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    string location = "start";
    int health = 3;
    string userChoice;
    string weapon = "fist";
    string keyend = "no";
    string healingPotion = "no";
    bool win = false;
    bool hasFoundKnife = false;
    bool hasStarted = false;
    int monsterHealth = 1;
    int attack;
    int goblinHealth = 4;
    int skeletonHealth = 20;
    
    std::cout << "NOTE: To access a help list, just press the ? key anytime. You can also type 'q' or 'Q' anytime to quit the game\n\n";
    std::cout << "What is your name?\n";
    std::cin >> name;
    
    
    while (userChoice != "q" && userChoice != "Q")
    {
        
        if (weapon == "fist")
        {
            attack = 1;
        }
        
        if (weapon == "small knife")
        {
            attack = 2;
        }
        
        if (weapon == "sword")
        {
            attack = 3;
        }
        
        if (weapon == "gun")
        {
            attack = 4;
        }
        if (userChoice == "?") {
            cout << "The controls for moving around are north, east, south, and west. You can shorten it by just typing the first letter. \nEg: Instead of typing east, I can type e. In each room there are different commands to do. The commands are usually related to the item you are trying to use. Some examples are, openchest/oc, ladder, sword, gun, and cut \nIf you have a heal potion, you can type 'h' to use it.\n\n";
        }
        if (location == "start")
        {
            if (hasStarted == false) {
                std::cout << "Alright, " << name << ". You find your self in a dark room. There is a door to your north, south, east and west.\n";
                hasStarted = true;
            }
            else if (hasStarted == true) { //This is just so that it does not say "Alright, (name) every time you go back to the start
                std::cout << "You find your self in a dark room. There is a door to your north, south, east and west.\n";
            }
            std::cin >> userChoice;
            
            if (userChoice == "West" || userChoice == "west" || userChoice == "w")
            {
                location = "west";
            }
            
            else if (userChoice == "East" || userChoice == "east" || userChoice == "e")
            {
                location = "east";
            }
            
            else if (userChoice == "North" || userChoice == "north" || userChoice == "n")
            {
                location = "north";
            }
            
            else if (userChoice == "south" || userChoice == "South" || userChoice == "s")
            {
                location = "south";
            }
            
            else if (userChoice == "h" && healingPotion == "yes")
            {
                health = health + 15;
                healingPotion = "used";
                std::cout << "You have been healed! Your health is now " << health << ".\n";
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
        }
        
        if (location == "West" || location == "west" || location == "w")
        {
            location = "west";
            std::cout << "There is a chest in the middle of the room.\n";
            std::cin >> userChoice;
            
            if (userChoice == "openchest" || userChoice == "oc")
            {
                if (weapon != "small knife" && hasFoundKnife == false) {
                    std::cout << "You have found a small knife in the chest, your attack is stronger now.\n";
                    weapon = "small knife";
                    hasFoundKnife = true;
                }
                else if (hasFoundKnife == true) {
                    std::cout << "The chest is empty.\n";
                }
            }
            
            else if (userChoice == "start" || userChoice == "Start" || userChoice == "e" || userChoice == "east" || userChoice == "back")
            {
                location = "start";
            }
            
            else if (userChoice == "h" && healingPotion == "yes")
            {
                health = health + 15;
                healingPotion = "used";
                std::cout << "You have been healed! Your health is now " << health << ".\n";
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
        }
        
        if (location == "east")
        {
            std::cout << "There is a ladder and a dark cave towards the back of the room.\n";
            std::cin >> userChoice;
            
            if (userChoice == "ladder" || userChoice == "climbladder" || userChoice == "c" || userChoice == "l" || userChoice == "cl")
            {
                if (weapon == "sword") {
                std::cout << "You broke the lock at the top of the ladder and climed up.\n";
                location = "forest";
                }
                else if (weapon != "sword") {
                    std::cout << "There is a lock at the top of the ladder that you can't break.\n";
                }
            }
            
            else if (userChoice == "cave")
            {
                location = "cave";
            }
            
            else if (userChoice == "start" || userChoice == "Start" || userChoice == "s" || userChoice == "w" || userChoice == "west")
            {
                location = "start";
            }
            
            else if (userChoice == "h" && healingPotion == "yes")
            {
                health = health + 15;
                healingPotion = "used";
                std::cout << "You have been healed! Your health is now " << health << ".\n";
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
        }
        
        if (location == "forest" && healingPotion == "no")
        {
            std::cout << "You are surrounded by a dense forest on all sides.  In front of you, you think you see something shining through some branches that are a little more thin. You might be able to cut through them.\n";
            std::cin >> userChoice;
            
            if (userChoice == "east" || userChoice == "East" || userChoice == "e")
            {
                location = "east";
            }
            
            else if (userChoice == "cut" || userChoice == "c")
            {
                healingPotion = "yes";
                std::cout << "You have cut through the branches and found a potion of healing. Press h to heal yourself.\n";
                
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
        }
        
        if (location == "forest" && healingPotion == "yes")
        {
            
            std::cout << "The branches everywhere but back down the ladder to the east room are too thick to cut through.\n";
            std::cin >> userChoice;
            
            if (userChoice == "east" || userChoice == "East" || userChoice == "e")
            {
                location = "east";
            }
            
            else if (userChoice == "cut" || userChoice == "c")
            {
                std::cout << "The branches everywhere but back down the ladder to the east room are too thick to cut through.\n";
                std::cin >> userChoice;
            }
            
            if (userChoice == "h")
            {
                health = health + 15;
                healingPotion = "used";
                std::cout << "You have been healed! Your health is now " << health << ".\n";
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
        }
        
        if (location == "forest" && healingPotion == "used")
        {
            
            std::cout << "The branches everywhere but back down the ladder to the east room are too thick to cut through.\n";
            std::cin >> userChoice;
            
            if (userChoice == "east" || userChoice == "East" || userChoice == "e")
            {
                location = "east";
            }
            
            else if (userChoice == "cut" || userChoice == "c")
            {
                std::cout << "The branches everywhere but back down the ladder to the east room are too thick to cut through.\n";
                std::cin >> userChoice;
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
        }
        
        
        if (location == "cave" && skeletonHealth > 0)
        {
            std::cout << "There is a skeleton in this room.  It approaches you to fight.\n";
            std::cout << "The skeleton's health is " << skeletonHealth << ". Your health is " << health << ".\n";
            std::cout << "The skeleton's attack is 2. Your attack is " << attack << ".\n";
            cout << "Press f to fight or press e to go back to the east room.\n";
            cin >> userChoice;
            
            if (userChoice == "fight" || userChoice == "f")
            {
                while (skeletonHealth > 0 && health > 0 && location != "east")
                {
                    std::cout << "You have a " << weapon << ". Press a to attack.\n";
                    std::cin >> userChoice;
                    
                    if (userChoice == "east" || userChoice == "e")
                    {
                        cout << "You ran away from the fight.\n";
                        location = "east";
                    }
                    
                    else if ((userChoice == "h" && healingPotion == "yes") || (userChoice == "health" && healingPotion == "yes"))
                    {
                        cout << "You gained health.\n";
                        health = health + 15;
                        healingPotion = "used";
                    }
                    
                    else if (userChoice == "a")
                    {
                        skeletonHealth = skeletonHealth - attack;
                        std::cout << "The skeleton's health is " << skeletonHealth << ". The skeleton attacks!\n";
                        health = health - 2;
                        std::cout << "Your health is " << health << ".\n";
                    }
                    
                    else if (userChoice != "h" && healingPotion == "no" || healingPotion == "used")
                    {
                        std::cout << "I don't understand.\n";
                    }
                    
                }
            }
            
            else if (userChoice == "east" || userChoice == "b" || userChoice == "e" || userChoice == "back" || userChoice == "run")
            {
                cout << "You ran away from the fight.\n";
                location = "east";
            }
        }
        
        if (location == "cave" && skeletonHealth < 0 && weapon == "sword")
        {
            std::cout << "You have defeated the skeleton! The skeleton dropped a gun when you killed him.\n";
            std::cin >> userChoice;
            
            if (userChoice == "gun")
            {
                std::cout << "You have obtained the gun.\n";
                weapon = "gun";
            }
            else if (userChoice == "east" || userChoice == "e")
            {
                location = "east";
            }
        }
        
        if (location == "cave" && skeletonHealth < 0 && weapon != "sword")
        {
            std::cout << "The skeleton's dead body lays in this room.\n";
            std::cin >> userChoice;
            
            if (userChoice == "east"|| userChoice == "e")
            {
                location = "east";
            }
        }
        
        if (location == "north")
        {
            location = "north";
            std::cout << "You stand in the entrance of a hallway with a door on the left and right side of you.\n";
            std::cin >> userChoice;
            
            if (userChoice == "start" || userChoice == "s" || userChoice == "back")
            {
                location = "start";
            }
            
            else if (userChoice == "left" || userChoice == "leftdoor" || userChoice == "l" || userChoice == "ld")
            {
                location = "left door";
            }
            
            else if (userChoice == "right"|| userChoice == "rightdoor"|| userChoice == "r"|| userChoice == "rd")
            {
                location = "right door";
            }
            
            else if (userChoice == "hallway" || userChoice == "h")
            {
                location = "hallway";
            }
            
            else if (userChoice == "h" && healingPotion == "yes")
            {
                health = health + 15;
                healingPotion = "used";
                std::cout << "You have been healed! Your health is now " << health << ".\n";
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
        }
        
        if (location == "hallway" && keyend == "no")
        {
            std::cout << "You found mysterious key and you don't know what it goes too.\n";
            keyend = "yes";
        }
        
        if (location == "hallway" && keyend == "yes")
        {
            std::cout << "You stand in an empty hallway.\n";
            std::cin >> userChoice;
            
            if (userChoice == "north" || userChoice == "n")
            {
                location = "north";
            }
        }
        
        if (location == "left door")
        {
            std::cout << "The room is empty, and it was a trap. Once you walked in the door shut by itself and locked, not letting you to leave.  You slowly perished over a span of several days.\n";
            health = health - 3;
        }
        
        if (location == "right door" && goblinHealth >0)
        {
            std::cout << "There is a goblin in this room.  It approaches you to fight.\n";
            std::cout << "The goblin's health is " << goblinHealth << ". Your health is " << health << ".\n";
            std::cout << "The goblin's attack is 1. Your attack is " << attack << ".\n";
            cout << "Press f to fight or press n to go back to the north room.\n";
            cin >> userChoice;
            
            if (userChoice == "fight" || userChoice == "f")
            {
                
                while (goblinHealth > 0 && health > 0 && location != "north")
                {
                    std::cout << "You have a " << weapon << ". Press a to attack.\n";
                    std::cin >> userChoice;
                    
                    if (userChoice == "north" || userChoice == "n" || userChoice == "run" || userChoice == "back" || userChoice == "left")
                    {
                        cout << "You ran away from the fight.\n";
                        location = "north";
                    }
                    
                    
                    else if (userChoice == "a")
                    {
                        goblinHealth = goblinHealth - attack;
                        std::cout << "The goblin's health is " << goblinHealth << ". The goblin attacks!\n";
                        health = health - 1;
                        std::cout << "Your health is " << health << ".\n";
                    }
                    
                    else if (userChoice == "h" && healingPotion == "yes" || userChoice == "health" && healingPotion == "yes")
                    {
                        cout << "You gained health.\n";
                        health = health + 15;
                        healingPotion = "used";
                        
                        
                    }
                    
                    else if (userChoice != "h" && healingPotion == "no" || healingPotion == "used")
                    {
                        std::cout << "I don't understand.\n";
                    }
                }
            }
            
            else if (userChoice == "north" || userChoice == "b" || userChoice == "n" || userChoice == "back")
            {
                cout << "You ran away from the fight.\n";
                location = "north";
            }
        }
        
        if (location == "right door" && goblinHealth == 0 && weapon != "small knife")
        {
            std::cout << "The dead goblin lays in this room.\n";
            std::cin >> userChoice;
            
            if (userChoice == "north" || userChoice == "North" || userChoice == "n" || userChoice == "back" || userChoice == "left")
            {
                location = "north";
            }
            
            else if (userChoice == "h" && healingPotion == "yes")
            {
                health = health + 15;
                healingPotion = "used";
                std::cout << "You have been healed! Your health is now " << health << ".\n";
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
            
        }
        
        if (location == "right door" && goblinHealth == 0 && weapon == "small knife")
        {
            std::cout << "You have defeated the goblin! He dropped his sword on the ground when you defeated him.\n";
            std::cin >> userChoice;
            
            if (userChoice == "sword")
            {
                std::cout << "You have picked up the sword. Your attack is stronger now.\n";
                weapon = "sword";
            }
            
            if (userChoice == "north"|| userChoice == "North"|| userChoice == "n")
            {
                location = "north";
            }
        }
        
        if (location == "south" && monsterHealth > 0)
        {
            location = "south";
            std::cout << "There is a huge monster in this room. It has huge claws and teeth, and looks very hard to kill. It approaches you. What do you do?\n";
            std::cin >> userChoice;
            
            if (userChoice == "start" || userChoice == "beginning" || userChoice == "n" || userChoice == "run" || userChoice == "back")
            {
                location = "start";
            }
            
            else if ((userChoice == "attack" && weapon != "gun") || (userChoice == "a" && weapon != "gun") || (userChoice == "fight" && weapon != "gun"))
            {
                std::cout << "You weren't strong enough to kill the monster with your " << weapon << ". It easily killed you.\n";
                health = health - 20;
            }
            
            else if ((userChoice == "attack" && weapon == "gun") || (userChoice == "a" && weapon == "gun"))
            {
                std::cout << "You shot and killed the monster! As his body falls you see a door behind him.\n";
                monsterHealth = monsterHealth - attack;
                
            }
            
            else if (userChoice == "h" && healingPotion == "yes")
            {
                health = health + 15;
                healingPotion = "used";
                std::cout << "You have been healed! Your health is now " << health << ".\n";
            }
        }
        
        if (location == "south" && monsterHealth < 0)
        {
            std::cout << "You see a door behind the monster's body.\n";
            cin >> userChoice;
            if ((userChoice == "door" && keyend == "yes") || (userChoice == "d" && keyend == "yes"))
            {
                win = true;
            }
            
            else if (userChoice == "start" || userChoice == "beginning" || userChoice == "s")
            {
                location = "start";
            }
            
            else if ((userChoice == "door"  && keyend == "no") || (userChoice == "d" && keyend == "no"))
            {
                std::cout << "The door is locked.\n";
            }
            
            else if (userChoice == "h" && healingPotion == "yes")
            {
                health = health + 15;
                healingPotion = "used";
                std::cout << "You have been healed! Your health is now " << health << ".\n";
            }
            
            else
            {
                std::cout << "I don't understand.\n";
            }
        }
        
        
        
        if (win == true)
        {
            std::cout << "You walk out of the door in relief, but you still have no idea where you are.  As reality hits you with a smack, a cold sweat beads down your forehead. Congratulations! You have beat my game!";
            userChoice = "q";
        }
        
        
        if (health == 0 || health <0)
        {
            std::cout << "Game over, you lose.\n";
            userChoice = "q";
        }
        
    }
    std::cin >> userChoice;
    
    return 0;
}
