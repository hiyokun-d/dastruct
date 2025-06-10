// This file gonna so sussy baka dawg, AW HELL NAHHHHH FREAKY AF
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this code is made by hiyo with love
// https://github.com/hiyokun-d

// just for the easter egg (pls don't kill me)
#include <unistd.h>
// #include <windows.h>
int easterEGGMENU = 0;

#define ALPHABET_SIZE 26

typedef struct TrieNode
{
       struct TrieNode *children[ALPHABET_SIZE];
       char *description;
} TrieNode;

TrieNode *createNode()
{
       TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
       for (int i = 0; i < ALPHABET_SIZE; i++)
       {
              node->children[i] = NULL;
       }

       node->description = NULL;
       return node;
}

void insert(TrieNode *root, const char *word, const char *description)
{
       TrieNode *curr = root;
       for (int i = 0; word[i] != '\0'; i++)
       {
              char ch = tolower(word[i]);
              if (ch < 'a' || ch > 'z')
                     continue;
              int index = ch - 'a';
              if (curr->children[index] == NULL)
              {
                     curr->children[index] = createNode();
              }
              curr = curr->children[index];
       }

       if (curr->description != NULL)
       {
              free(curr->description);
       }

       curr->description = (char *)malloc(strlen(description) + 1);
       strcpy(curr->description, description);
}

void search(TrieNode *root, const char *word)
{
       TrieNode *curr = root;
       for (int i = 0; word[i] != '\0'; i++)
       {
              char ch = tolower(word[i]);
              if (ch < 'a' || ch > 'z')
                     continue;

              int index = ch - 'a';
              if (curr->children[index] == NULL)
              {
                     printf(
                         "The Slang %s word is skibidi and no rizz have no aura, no cap frfr "
                         "(not found :v)\n",
                         word);
                     return;
              }
              curr = curr->children[index];
       }

       if (curr->description != NULL)
              printf("Yapyap for '%s': %s\n", word, curr->description);
       else
              printf("The Slang %s word is skibidi and no rizz have no aura, no cap frfr "
                     "(not found :v)\n",
                     word);
}

void printAllWords(TrieNode *node, char *buffer, int depth)
{
       if (node == NULL)
              return;
       if (node->description != NULL)
       {
              buffer[depth] = '\0';
              printf("[+100AURA] %s: %s\n", buffer, node->description);
       }
       // this code is made by hiyo with love
       // https://github.com/hiyokun-d

       for (int i = 0; i < 26; i++)
       {
              if (node->children[i] != NULL)
              {
                     buffer[depth] = 'a' + i;
                     printAllWords(node->children[i], buffer, depth + 1);
              }
       }
}
// this code is made by hiyo with love
// https://github.com/hiyokun-d
void searchByPrefix(TrieNode *root, const char *prefix)
{
       TrieNode *curr = root;
       char buffer[100];

       for (int i = 0; prefix[i] != '\0'; i++)
       {
              char ch = tolower(prefix[i]);
              if (ch < 'a' || ch > 'z')
                     continue;

              int index = ch - 'a';
              if (curr->children[index] == NULL)
              {
                     printf("hellnahh DaWG We AIn't Got THat WOrd WIht THE '%s' PRefix hel "
                            "Nah 💀💀💀💀(not found :v)\n",
                            prefix);
                     return;
              }

              curr = curr->children[index];
       }

       strcpy(buffer, prefix);
       printAllWords(curr, buffer, strlen(prefix));
}
// this code is made by hiyo with love
// https://github.com/hiyokun-d
void koboKan()
{
       printf("                            :-:-:::     ::..:::::=                   "
              "                               \n");
       printf("                           -======..  =:.:.=---::::                  "
              "                                \n");
       printf("                          -:-    ==.-=:.::- ------..                 "
              "                                \n");
       printf("               -.=       :::=      =:::-       -=:-..                "
              "                                \n");
       printf("                ..       ::::.-    --:=         -.::..               "
              "                                \n");
       printf("       =...*    :.=     = -:::      =-          -.....               "
              "                                \n");
       printf("         *...=   ::           -::-.....::..     ::.::.               "
              "                                \n");
       printf("           *:::  ::        =:--=:::=+::::::..      :                 "
              "                                \n");
       printf("             *:: ::      +:==+*  =:---:: -::..:                      "
              "                                \n");
       printf("          *+==+:-::     =:*+:+::-:  :::-:: ::.:-:                    "
              "                                \n");
       printf("       *======.:...:   =*=+--=:::--. :::-:: -:::::                   "
              "                                \n");
       printf("      *+=+*=.:::::-*:-:-=++-:=:--: -  ..=:-:::===:.:                 "
              "                                \n");
       printf("      +=====-::=-:=-=*+::++:-::::-::-  . ::=::::-:..:                "
              "                                \n");
       printf("     *=+==*===-=-*+#=+=+=+-+==:-*:--:: .. .-=::==:...                "
              "                                \n");
       printf("     ++===hiyo==:-=*=-=-=+==*+:-=-::::===-.. .==::-:....               "
              "                                \n");
       printf("    ++==++=====+=kobo-=+=+-==:= -:=.=..-.= .-==:::..::.              "
              "      ..                        \n");
       printf("    *==+++++=:====-=++-=*-+=.+.*::-:#*.:-:. ..::-:-:.::.             "
              "     .....                      \n");
       printf("    +====++++======++ -:+*:=:-::::::.:=..:. .::*=:=:.::..            "
              "  ........                      \n");
       printf("    ======hiyo====+.:::.:.:*:\%%##::::::.::::....#+==:=:=:::.    :.:. "
              " :   ::... ::                     \n");
       printf("    ---=========\%% .  :.:*+==::::..::::::::.-===:::-.===::..:.....  "
              ":.:.::.....:..:  :.               \n");
       printf("     +----=-==*:.  ..  .:**==::::::===::::+=--.=-==-::::-::...... "
              "-::.:........    :::               \n");
       printf("       "
              "=--=\%%\%%--::..:.:...:--=+::::---:::#=:**=+:--:=::=:-+=-:-:--::...:."
              ".  ....::..:::               \n");
       // this code is made by hiyo with love
       // https://github.com/hiyokun-d
       printf("         "
              "*=:==-==--::.:::..:=++++*::::===-#==*=+-=:--:::+=====-:-::..::::  "
              ".:-..:...::::::           \n");
       printf("           ==-:====:::::::-:-*+*+++#++==-:-+::**=-:=::=:-.:.====---  "
              "       :::.:. ::::..:           \n");
       printf("             *=======:::::-:--*:*-++++:---===*=:---: "
              "::+-:..:====-=--:.:::::..::::::::.::::          \n");
       printf("               +-:--::=:::=-*+=++=:#======----:=-::::=   :.:= "
              "=::==---::::--:::::::--:....:          \n");
       printf("                   -====*-=----*====+=*=-==:=:=-:: .-:-*  ::    "
              "=::::::::::.::::---:::::            \n");
       printf("                         *+:+:=======-===*:--=.:::::::::+  :      "
              ":::.:::::::::::::::::.:. : :      \n");
       printf("                         *..=..+:::\%%=*::+.::-... :-:  :::-        "
              ":..:  :::-:::..::::::::.::        \n");
       printf("                      * :=...=.=..\%%#:+:..+.#::..:::..  :::-       "
              "\%%**+**+..::::::.::.:::::          \n");
       printf("                    *     :.  :....:.+-=:-+:::::::::.. ...:=   "
              "\%%****+*+=::=::::  :::.::::  ::       \n");
       printf("                       = :: .#.   .. "
              "+:....:::::-:::......::+**+#+**-*--===+ :::   ..::.:::          \n");
       printf("                *      - :::::.. \%%   *.   "
              "..==-:=-::......:+++==\%%++-=*=*+++=*       ::::...:         \n");
       printf("                        :::**: ::: . *    "
              ".::=::=--::-::.-\%%+====#--:=::===-:::=     :  :   :         \n");
       printf("                        *::+:*.*::::. . ...:::== "
              "=+===:***\%%++===*=+*-+-:=*==+*                      \n");
       printf("                       -*#:::-::-::=::+...:=-.: : "
              "=-====*##=+====*==*=:-:+*+=*                      \n");
       printf("                       ==#::-#::-#::::+::....::. "
              ":===-=:=-#=+=====*+*=+*=*+*+                       \n");
       printf("                       "
              "-=#\%%=-*:::---::+::::::::::+===-=:==*=++=+==*=+*#*++*+              "
              "          \n");
       printf("                        "
              "=#\%%:-=-:--#=--=:::::::::*++:=*=--:--========:=+=+**                "
              "         \n");
       printf("                          "
              "\%%\%%:***+::=-:+:::::::\%%***::::.=-==#++======+++=*                "
              "           \n");
       printf(
           "                           *==-:********====****#-=--::=:=-#--========* "
           "                            \n");
       printf("                            =+-::::#\%%*:**=+++:::-------* "
              "::+*-------*                               \n");
       printf("                            =.-*::::#+:=...:::.::=----=:::-::        "
              "                                \n");
       printf("                              -=#::...::-+=:::::::+::--====-         "
              "                                \n");
       printf("                               *=#=:..::-:=..::::::*-==:==-          "
              "                                \n");
       printf("                               = =#+::.::::...*:::===:==-            "
              "                                 \n");
       printf("                               +    -::..::==::==-=-===:.=           "
              "                                 \n");
       printf("                                      ::.:**==-===-=:::::::=         "
              "                                 \n");
       printf("                                       *-:-.:=  +   *:.:::::.        "
              "                                 \n");
       printf("                                         =:=+*  =     =:-::::        "
              "                                 \n");
       printf("                                           **::  =     +::::*        "
              "                                 \n");
       printf("                                            *:.         +*#**        "
              "                                 \n");
       printf("                                              :*        *:::*        "
              "                                 \n");
       printf("                                             =+*=        :::         "
              "                                 \n");
       printf("                                              -::==    *-*:+         "
              "                                 \n");
       printf("                                              =-=*+    *+-*          "
              "                                 \n");
       printf("                                               *++   =-*:++          "
              "                                 \n");
       printf("                                                     +=**=           "
              "                                 \n");
       printf("                                                                     "
              "                                \n");
}
// this code is made by hiyo with love
// https://github.com/hiyokun-d
void menu()
{
       printf("\n");
       if (easterEGGMENU)
       {
              printf(
                  "🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n");
              printf("🧌 WELCOME TO BOOGLE — THE SLANGOSPHERE OF PURE CHAOS 💬\n");
              printf("📟 Coded in 100%% pain, compiled with unhinged energy ⚙️💀\n");
              printf("🧠 This isn't a dictionary. This is an EXPLOSION.\n");
              printf("🎮 Mode: Terminal-core | Rizz Level: OFF THE CHARTS 💯\n");
              printf("🔊 Soundtrack: Keyboard smashing and distant modem noises\n");
              printf("🌐 Runtime Detected: BRAINROT++.exe\n");
              printf(
                  "🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n\n");
       }
       else
       {
              printf("███████╗ ██████╗  ██████╗  ██████╗ ██╗     ███████╗\n");
              printf("██╔════╝██╔═══██╗██╔═══██╗██╔═══██╗██║     ██╔════╝\n");
              printf("█████╗  ██║   ██║██║   ██║██║   ██║██║     █████╗  \n");
              printf("██╔══╝  ██║   ██║██║   ██║██║   ██║██║     ██╔══╝  \n");
              printf("██║     ╚██████╔╝╚██████╔╝╚██████╔╝███████╗███████╗\n");
              printf("╚═╝      ╚═════╝  ╚═════╝  ╚═════╝ ╚══════╝╚══════╝\n");
              printf("      💥 BOOGLE v9000: TERMINAL RIZZ APOCALYPSE 💥\n");
              printf("-----------------------------------------------------\n");
              printf("😤 You just entered the BRAINROT BLAST ZONE™ ‼️\n");
              printf("💬 Type like you're spittin’ facts on Discord at 3AM.\n");
              printf("🛸 Slang so hot it makes ChatGPT self-destruct...\n");
              printf("📟 Bootin’ up max sauceness. Please stand by...\n");
              printf("shhhh.... you can type 666, 420, and 69 too ifynkn\n");
              printf("-----------------------------------------------------\n\n");
       }
       // this code is made by hiyo with love
       // https://github.com/hiyokun-d
       printf("📜 MENU OPTIONS (still somehow readable):\n");
       printf("1. ✍️  Drop a new slang (Certified 🔥 only)\n");
       printf("2. 🔍 Find the lore of a slang (No mid allowed)\n");
       printf("3. 🧩 Peep all slang by prefix (Viral-only filter on)\n");
       printf("4. 📚 Dump the full slang archive (Warning: it's loud)\n");
       printf("5. 💨 Log out before your brain melts frfr\n");

       printf("\n🧠 Choose your chaotic move [1–5] or perish: \n");
}
// this code is made by hiyo with love
// https://github.com/hiyokun-d
void freeTrie(TrieNode *root)
{
       if (root == NULL)
              return;
       // this code is made by hiyo with love
       // https://github.com/hiyokun-d
       for (int i = 0; i < 26; i++)
       {
              if (root->children[i] != NULL)
              {
                     freeTrie(root->children[i]);
              }
       }
       // this code is made by hiyo with love
       // https://github.com/hiyokun-d
       if (root->description != NULL)
       {
              free(root->description);
       }

       free(root);
}
// this code is made by hiyo with love
// https://github.com/hiyokun-d

int main()
{
       TrieNode *root = createNode();
       char word[100], description[256], prefix[100], buffer[100];
       int choice;
       // this code is made by hiyo with love
       // https://github.com/hiyokun-d
       printf("\n😤🔥 WELCOME TO BOOGLE — THE ULTIMATE SLANG HOARD 🧠💥\n");
       printf("🚨 WARNING: Entering a zone of certified brainrot...\n");
       printf("💬 Say less, type more. Let’s slang this thang.\n\n");
       printf("Just press [enter] twice\n");
       while (getchar() != '\n')
              ;
       getchar();

       do
       {
              // this code is made by hiyo with love
              // https://github.com/hiyokun-d
              menu();
              scanf("%d", &choice);
              getchar();
              switch (choice)
              {
              case 1:
                     printf("Enter new slang word (no spaces): ");
                     scanf("%s", word);
                     getchar();
                     printf("Enter description (must be more than 2 words): ");
                     fgets(description, sizeof(description), stdin);
                     description[strcspn(description, "\n")] = 0;
                     int words = 0;
                     for (int i = 0; description[i]; i++)
                     {
                            if ((i == 0 || description[i - 1] == ' ') && description[i] != ' ')
                                   words++;
                     }

                     if (strlen(word) <= 1 || strchr(word, ' ') || words < 2)
                     {
                            printf("❌ Invalid input. Slang must be >1 char, no space, and "
                                   "description >1 words.\n");
                     }
                     else
                     {
                            insert(root, word, description);
                            printf("✅ Slang '%s' has been added/updated!\n", word);
                     }
                     break;
                     // this code is made by hiyo with love
                     // https://github.com/hiyokun-d
              case 2:
                     printf("Enter slang word to search: ");
                     scanf("%s", word);
                     search(root, word);
                     break;

              case 3:
                     printf("Enter prefix: ");
                     scanf("%s", prefix);
                     printf("Matching slang words for prefix '%s':\n", prefix);
                     searchByPrefix(root, prefix);
                     break;

              case 4:
                     printf("All slang words (sorted):\n");
                     printAllWords(root, buffer, 0);
                     break;
                     // this code is made by hiyo with love
                     // https://github.com/hiyokun-d
              case 5:
                     printf("\n🧠💥 BRUH MOMENT ACTIVATED 💥🧠\n");
                     printf("You finna dip fr fr? No cap. W rizz detected.\n");
                     printf("Yeeted outta Boogle like it’s 2016...\n");
                     printf("🚀💨 Skrrt skrrt. Sus levels dropping. Go touch grass now. 🌱\n");
                     printf("Catch ya on the flipside, simp-squad 😤🔥\n");
                     printf("🫡 Shutting down the sauce engine. Stay based.\n\n");
                     freeTrie(root);
                     break;
              case 69:
                     printf("\n🌈💫 YOU FOUND THE SECRET RIZZGATE 💫🌈\n");
                     printf("🥵 Your fingers typed 69, which means you’re either legendary or "
                            "deeply unwell.\n");
                     printf("🔥 Initiating Terminal Overhype Protocol: RIZZMODE ∞\n");
                     printf("👑 All your slang are now canon. Urban Dictionary who?\n");
                     printf("📼 Now playing: Never Gonna Give You Up in 240p ASCII\n");
                     printf("🎉 Achievement Unlocked: \"Certified Boogle Enthusiast 💯\"\n");
                     printf("💥 Memory leak? Nah. Just your brain overflowing with vibes.\n");
                     printf("📟 Bonus fact: The dev of this program is 98%% water and 2%% "
                            "stress.\n");
                     printf("💀 Now exiting... or are we? 👁️👄👁️\n\n");
                     break;
              case 420:
                     printf("\n🚬🌿 INITIATING ULTRA CHILL PROTOCOL: CODE BLAZE 420 🌿🚬\n");
                     printf(
                         "😵 You just unlocked the final form of Boogle... The Danknary.\n");
                     printf("🧙‍♂️ Wisdom: \"Every ‘sus’ has a ‘us’... stay "
                            "woke, "
                            "gamer.\"\n");
                     // this code is made by hiyo with love
                     // https://github.com/hiyokun-d
                     printf("🔥 Slang so potent it requires a syntax license.\n");
                     printf("🌐 Dialing into the deep web of vocabulary...\n");
                     printf("😶‍🌫️ Processing... gigabrain activity detected.\n");
                     printf("💸 Tip: Selling this code as an NFT would be a crime and a "
                            "service.\n");
                     printf("🎮 Ending simulation in...\n");
                     for (int i = 5; i >= 1; i--)
                     {
                            printf("    %d...\n", i);
                            sleep(1); // Use Sleep(1000); on Windows instead
                     }
                     printf("👋 Logged out of reality. Goodbye, terminal traveler.\n\n");
                     break;
              case 666:
                     easterEGGMENU = 1;
                     printf("\n😈 YOU HAVE SUMMONED...\n");
                     printf("🔔 CLIPPY FROM TERMINAL HELL 🔔\n");
                     printf("📎 'It looks like you're trying to slang beyond mortal "
                            "limits...'\n");
                     printf("💾 Auto-saving all cringe to C:/Soul_Backup.exe\n");
                     printf("🩸 Blood pact initiated. Compiling cursed macros...\n");
                     printf("📉 Syntax sanity dropping: [███████░░░] 69%%\n");
                     printf("🎤 CLIPPY: \"May your pointers always be wild and your stack "
                            "always overflow.\"\n");
                     printf("💀 Boogle.exe is now haunted. Expect segmentation faults in your "
                            "sleep.\n\n");
                     break;
              default:
                     printf("❗ Invalid choice. Please enter 1–5.\n");
              }

              printf("Just press [enter] twice (for extra security)\n");
              while (getchar() != '\n')
                     ;
              getchar();
       } while (choice != 5);

       koboKan();

       freeTrie(root);
       return 0;
}
// this code is made by hiyo with love
// https://github.com/hiyokun-d
/* TEST CASE - SOURCE: my lil friend GPT
   insert(root, "sus", "suspicious behavior");
  insert(root, "yeet", "to throw something forcefully");
  insert(root, "simp", "someone who does too much for someone they like");
  insert(root, "sus", "updated: still suspicious"); // overwrite test
  insert(root, "savage", "cool or bold in a crazy way");
  insert(root, "ship", "to support a romantic relationship");

  // 🔎 Search exact
  printf("\n=== Search Tests ===\n");
  search(root, "sus");     // should show updated description
  search(root, "yeet");    // should show original description
  search(root, "unknown"); // should not be found

  printf("\n=== Prefix Search Tests ===\n");
  searchByPrefix(root, "s");  // should list sus, simp, savage, ship
  searchByPrefix(root, "sh"); // should list ship
  searchByPrefix(root, "z");  // should say not found

  // 📚 Print all in order
  printf("\n=== All Sorted Slang Words ===\n");
  char buffer[100];
  printAllWords(root, buffer, 0);
*/