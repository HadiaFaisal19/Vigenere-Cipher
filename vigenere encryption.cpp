#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string message;
string rep_key;
string encrypt;
string decrypt;
string key;


void input()   
{                              //taking input from the user and changing the alphabets into upper case.
    string text, key;
    
	cout<<" THE TEXT AND KEY SHOULD ONLY CONTAIN ALPHABETS !                     *"<<endl;
	cout<< "                    *                                                                                                                        *"<<endl;
	cout<< "                    *                                                                                                                        *"<<endl;
    cout<<endl;
    cout<<"                                                                  "<<endl;
    cout<<"                                                                  ENTER TEXT: ";
    
    getline (cin, text);

    for (int i=0; i<text.length(); i++)      // here 'i' will store the characters of text one by one.
    {
        text[i] = toupper(text[i]);         // this function will convert it into upper case
    }

    cout<<"                                                                  ENTER KEY:  ";
    getline (cin, key);

    for (int i =0; i<key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }

string mapping_key;                   //mapping key..: means that, the key will repeat itself untill the char of text and key r equal.
for (int i=0, j=0; i<text.length(); i++)
{
    if (text[i] == 32)                // 32 is ascii value of space.
    {
        mapping_key += 32;
    } 
    else if ( j<key.length() )       // key will repeat itself until it becomes equal to char in text
    {
       mapping_key += key[j];
       j++;
    }
    else 
    {
        j =0;
        mapping_key += key [j];
        j++;
    }
}
    
    message = text;            // making input text and key equal to global variables so that we can us them in functions easily.
    rep_key = mapping_key;
    //cout<<"                                                                       "<< message << endl ;  // display repetition of key untill it becomes equal to chars in message
    //cout<<"                                                                       "<< rep_key<< endl;
}

//making vigenere table 
int Vig_table_arr[26][26];  //making a global 2D array for displaying vigenere table
void Vigenere_Table()           
{
    for (int i=0; i<26; i++)
    {
       for (int j=0; j<26; j++)
    {
       int temp;
       if ((i + 65)+j > 90 )
       {
           temp = (( i + 65) + j) - 26;
           Vig_table_arr[i][j] = temp;
       }
       else
       {
           temp = (i + 65) + j;
           Vig_table_arr[i][j] = temp;
       }
    }
    }
    
}

    //ENCRYPTION
     // this is a formula of vigenere ecryption
void Vigenere_encryption(string message, string rep_key)
{
	Vigenere_Table();
    string encrypted_text = "";
    for (int i=0; i<message.length(); i++)
    {
        if (message[i] == 32 && rep_key[i] == 32)     // if space is given in text, it will not b encrypted, wilL b printed as it is
        {
            encrypted_text += " ";
        }
        else
        {
            int a = message[i] - 65;                
            int b = rep_key[i] - 65; 
            encrypted_text +=  Vig_table_arr[a][b];   // the point where the row and column chars wil concide it will store that char in encrypted_text
        }
    }
        cout<<"                                                                  ENCRYPTED TEXT: " << encrypted_text<<endl;                                                   
        encrypt = encrypted_text;
}

//FUNCTION FOR REVERSE MAPPING
int itrCount (int key, int msg){
	int counter = 0;
	string result = "";
	
	//starting from ASCII of letter of Key and ending at letter of message
	// to get full 26 letters of alphabet
	for (int i = 0; i < 26; i++)
	{
		if (key + i > 90){
			result += (char) (key+(i-26));    //typecasting
		} else {
			result += (char) (key+i);
		}
	} 
	
	for (int i = 0; i < result.length(); i++)       
	{
		if (result [i] == msg){
			break;
		} else {
			counter++;
		}
	}
	return counter;
}

// DECRYPTION
void Vigenere_decryption(string message, string rep_key)
{
    string decrypted_text = "";
    for (int i=0; i<message.length(); i++)
    {
        if (message[i] == 32 && rep_key[i] == 32)
        {
            decrypted_text += " ";   // if space is given in text, it will not b decrypted, wil b printed as it is
        }
        else 
        {
            int temp = itrCount  (rep_key[i], message [i]);  ///formula for decryption
			decrypted_text +=  (65 + temp);
		}
	}
	    cout<<"                    *                                             DECRYPTED TEXT:  "<< decrypted_text<<"                                      *"<<endl;                               
		decrypt = decrypted_text; 
}
  

        
int main()
{
	
	char filename[100];
    int choice, opt;
    ofstream fout;
	
	cout<< endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<< "                    **************************************************************************************************************************"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                    !!! ENCRYPTION AND DECRYPTION USING VIGENERE  CYPHER !!!                            *"<<endl;  
	cout<< "                    *                                                                                                                        *"<<endl;
	cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                            1. ENCRYPTION                                                               *"<<endl;
    cout<< "                    *                                            2. DECRYPTION                                                               *"<<endl;
    cout<< "                    *                                            3. TO VIEW VIGENERE TABLE                                                   *"<<endl;
    cout<< "                    *                                            ENTER ANY KEY TO EXIT THE PROGRAM...                                        *"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                            CHOOSE ANY ABOVE OPTION...                                                  *"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    **************************************************************************************************************************"<<endl;
    cout<<endl;
    cout<<endl;
	cout<< "                                                                ENTER YOUR CHOICE: ";
	cin>>choice;
	system ("cls");
	while(choice>0 && choice<4)  // so that program does not exit itself
    {
    cin.ignore();
    
    if (choice == 1)
    {
    	cout<< endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    	cout<<"                    **************************************************************************************************************************"<<endl;
    	cout<<"                    *                                                                                                                        *"<<endl;
        cout<<"                    *                                    FOR ENCRYPTION";
        input();
        
        
        Vigenere_encryption(message, rep_key);
		
		cout<<endl;
		cout<<"                                                              ENTER FILE NAME TO SAVE ENCRYPTED TEXT: ";
		cin>>filename;
		cout<<"                    *                                                                                                                        *"<<endl;                                                                      
		cout<<"                    *                                       !! THE TEXT IS SUCCESSFULLY ENCRYPTED INTO THE FILE !!                           *"<<endl;
		cout<<"                    *                                                                                                                        *"<<endl;
		cout<<"                    **************************************************************************************************************************"<<endl;
		//fout.open(filename);
		ofstream fout (filename ,ios::app);
		fout<<"ENCRYPTED TEXT: "<<encrypt<<endl;
    	fout.close();
        
		cout<<endl;
    }
    
    else if (choice == 2)
    {
    	cout<< endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    	cout<<"                    **************************************************************************************************************************"<<endl;
        cout<<"                    *                                    FOR DECRYPTION";
        input();
        
        //fout.open (filename);
		Vigenere_decryption(message, rep_key);
	
	    ofstream fout (filename ,ios::app);
		
		cout<<"                    *                                                                                                                        *"<<endl;                                                                                                                     
		cout<<"                    *                                      !! THE TEXT IS SUCCESSFULLY DECRYPTED INTO THE FILE !!                            *"<<endl;
		cout<<"                    *                                                                                                                        *"<<endl;
		cout<<"                    **************************************************************************************************************************"<<endl;
		fout<<"DECRYPTED TEXT: "<< decrypt<<endl;
    	fout.close();
		cout<<endl;
    }
    
    else if (choice == 3)
    {
    	Vigenere_Table();
    	
    	cout<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"                                                                      !!! VIGENERE TABLE !!!                                 "<<endl;
    	for (int i=0; i<26; i++) 
	{	   cout<<"                                                        ";    
    
        for (int j=0; j<26; j++)
        {
        	// displaying vigenere table
			cout<< (char) Vig_table_arr[i][j] <<" ";   //  typecasting
        }
        cout<< endl;
    }
		cout<<endl;
    }    
	
    else 
    {
	}

    cout<< endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    
    cout<< "                    **************************************************************************************************************************"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                            1. ENCRYPTION                                                               *"<<endl;
    cout<< "                    *                                            2. DECRYPTION                                                               *"<<endl;
    cout<< "                    *                                            3. TO VIEW VIGENERE TABLE                                                   *"<<endl;
    cout<< "                    *                                            ENTER ANY KEY TO EXIT THE PROGRAM...                                        *"<<endl;;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                            CHOOSE ANY ABOVE OPTION TO CONTINUE...                                      *"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    *                                                                                                                        *"<<endl;
    cout<< "                    **************************************************************************************************************************"<<endl;
    cout<<endl;
    cout<<endl;
    
    cout<< "                                                                 ENTER YOUR CHOICE: ";
	cin>>choice;
	system("cls");  //TO CLEAR THE SYSTEM 
    cout<<endl;
	}

    return 0;
}
