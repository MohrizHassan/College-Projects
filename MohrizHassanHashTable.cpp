            #include <string>
            #include <iostream>
            #include <stdlib.h>
            using namespace std;

        #define WEEDTABLESIZE 17
        #define TEST_KEYS 8

        void Insert_DoubleWeeding(string key);
        void print_table();
        void Insert_LinearProbing(string key);
        int search(string key);
        int weed_function(string key);

        struct entry
        {
            string key;
        };

         entry *hash_array[WEEDTABLESIZE];

        int weed_function(string key)
        {

            int sum = 0;
            for (int i = 0; i < key.length(); i++)
            {
                sum = sum + key[i];
            }


            int weed_index;

            weed_index = sum % WEEDTABLESIZE;

            return weed_index;
        }



        void Insert_LinearProbing(string key){


            struct entry *entry_p = new entry;
            entry_p->key = key;


            int weed_index;
            weed_index = weed_function(key);


            while (hash_array[weed_index] != NULL)
            {
                weed_index++;
                weed_index %= WEEDTABLESIZE;
            }

            hash_array[weed_index] = entry_p;
        }

        void Insert_DoubleWeeding(string key)
        {

            struct entry *entry_p = new entry;
            entry_p->key = key;

            int probe, offset;
            probe = weed_function(key);
            offset = probe *(WEEDTABLESIZE - 1) % WEEDTABLESIZE;
            cout << "the offest of " << key << " is: " << offset << endl;



            while (hash_array[probe] != NULL)
            {
                probe = probe + offset;
                probe %= WEEDTABLESIZE;
            }

            hash_array[probe] = entry_p;
        }

        void print_table()
        {

            cout << "Index\t" << "Name\n";
            for (int a = 0; a < WEEDTABLESIZE; a++)
            {
                cout << a << "\t";
                if (hash_array[a] != NULL)
                {
                    cout << hash_array[a]->key << endl;
                }
                else
                    cout << "~~~\n";
            }
            cout << endl;
        }

        int search(string key)
        {
            int weed_index = weed_function(key);


            while (hash_array[weed_index] != NULL)
            {
                if (hash_array[weed_index]->key == key)
                    return weed_index;

                weed_index++;
                weed_index %= WEEDTABLESIZE;
            }
            return NULL;
        }

        int main()
        {
            string name;
            string test_strings[TEST_KEYS] = { "Mohriz", "Namra", "Zoha", "Mahwish", "Amir", "Saad", "Namra", "Austin" };
            for (int a = 0; a < TEST_KEYS; a++)
            {

                Insert_DoubleWeeding(test_strings[a]);
            }

            print_table();
            int testing;
            testing = search("Namra");
            cout << "testing is: " << testing << endl;

            int KeepTerminalOpen;
            cin >> KeepTerminalOpen;
            return 0;
        }
