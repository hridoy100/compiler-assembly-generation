#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;



/*int collisionResolve = 0;
int hashFunc = 0;
int length;
int totalCapacity;
*/
///ofstream outputFile;



class SymbolInfo
{
private:
    string Name;
    string Type;

public:
    SymbolInfo *next = NULL;
    string type= "-1";
    vector<string> functionParameters;
    bool defined = false;
    string code;
    SymbolInfo(){
	code = "";
    }
    //Constructor of hashnode
    SymbolInfo(string key, string value)
    {
        this->Name = key;
        this->Type = value;
        code = "";
        //next = -1;
    }

    void setName(string s)
    {
        Name = s;
    }

    void setType(string s)
    {
        Type = s;
    }

    string getName()
    {
        return Name;
    }
    string getType()
    {
        return Type;
    }
};


class ScopeTable
{
    SymbolInfo **arr;
    int collision = 0;
    int size=0;
    int totalCapacity;
    int capacity;

    int hashFunc1(string key)
    {
        char *str = new char[key.length()];
        int i=0;
        int tmp=0;
        for(string::iterator it=key.begin(); it!=key.end(); ++it)
        {
            str[i++]=*it;
            tmp = int(*it)+(tmp*91);
            tmp%=capacity;
        }
        return tmp%capacity;
    }

public:
    int id=1;
    int exited=1;
    ScopeTable *parentScope = NULL;

    ScopeTable(int n)
    {
        //Initial capacity of hash array
        //capacity = 10000;
        capacity = n;
        size=0;
        arr = new SymbolInfo*[capacity];

        //Initialise all elements of array as NULL
        for(int i=0 ; i < capacity ; i++)
            arr[i] = NULL;

        //dummy node with value and key -1
        //dummy = new HashNode<K,V>(-1, -1);
        //dummy = new HashNode<K,V>("-1", -1);
    }

    ~ScopeTable()
    {
        for(int i=0 ; i < capacity ; i++)
            if(arr[i]!=NULL) delete arr[i];

    }

    //Function to add key value pair
    bool insertNode(string key, string value)
    {
        //SymbolInfo *temp = new SymbolInfo(key, value);
        SymbolInfo *temp = new SymbolInfo;
        temp->setName(key);
        temp->setType(value);

        // Apply hash function to find index for given key
        int hashIndex = hashFunc1(key);

        //check if overflow..
        if(size==capacity)
        {
            ///outputFile << "Overflow...\n\n";
            //cout << "Overflow detected...\n"<<endl;
            return false;
        }

        int tmpCollision = 0;

        SymbolInfo *sc = lookUp(key);
        if(sc->getName().compare("-1")!=0)
        {
            ///outputFile << "< " << key << ", " << value << "> already exists in current ScopeTable\n" << endl;
            //cout << "< " << key << ", " << value << "> already exists in current ScopeTable\n" << endl;
            return false;
        }
        //separate chaining...
        if(arr[hashIndex] != NULL && arr[hashIndex]->getName() != key && arr[hashIndex]->getName().compare("-1")!=0)
        {
            if(arr[hashIndex]->getName() == key)
            {
                ///outputFile << "< " << key << ", " << value << "> already exists in current ScopeTable\n" << endl;
                //cout << "< " << key << ", " << value << "> already exists in current ScopeTable\n" << endl;
                return false;
            }
            collision++;
            chaining(hashIndex, key, value);
        }
        else if(arr[hashIndex] == NULL || arr[hashIndex]->getName().compare("-1")==0) //also checks deleted node.
        {
            size++;
            arr[hashIndex] = temp;
            ///outputFile << "Inserted in ScopeTable# " << id <<" at position " << hashIndex << ", 0\n\n" ;
            //cout << "Inserted in ScopeTable# " << id <<" at position " << hashIndex << ", 0\n\n" ;
        }
        return true;


    }

    void chaining(int hashIndex, string key, string value)
    {
        int tmpCollision = 1;
        SymbolInfo *cur= arr[hashIndex];
        ///tmpCollision++;
        while(cur->next!=NULL && cur->getName() != key)
        {
            cur = cur->next;
            tmpCollision++;
        }

        //need to change here..
        //SymbolInfo *newNode = new SymbolInfo(key,value);
        SymbolInfo *newNode = new SymbolInfo;
        newNode->setName(key);
        newNode->setType(value);
        //newNode->key = key;
        //newNode->value = value;
        cur->next = newNode;
        ///outputFile << "Inserted in ScopeTable# " << id <<" at position " << hashIndex << ", " << tmpCollision <<endl << endl;
        //cout << "Inserted in ScopeTable# " << id <<" at position " << hashIndex << ", " << tmpCollision <<endl << endl;
        //collision+=tmpCollision;
    }

    SymbolInfo* chainSearch(int hashIndex, string key)
    {
        SymbolInfo *dummy = new SymbolInfo;
        dummy->setName("-1");
        dummy->setType("-1");
        if(arr[hashIndex]==NULL)
        {
            //cout << "Not Found\n";
            return dummy;
        }
        SymbolInfo *cur = arr[hashIndex];
        //while(cur->next!=NULL)
        int tmpCollision = 0;
        while(cur!=NULL)
        {
            if(cur->getName().compare(key)==0)
            {
//                return cur->value;
                ///outputFile <<  "Found in ScopeTable# " << id << " at position " << hashIndex << ", " <<tmpCollision <<endl << endl;
                //cout << "Found in ScopeTable# " << id << " at position " << hashIndex << ", " <<tmpCollision <<endl << endl;
                return cur;
            }
            cur = cur->next;
            tmpCollision++;
        }
        //cout << "Not Found\n";
        //unsuccessful search..
        return dummy;
    }

    //Function to search the value for a given key
    SymbolInfo* lookUp(string key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashFunc1(key);
        // chaining..
        SymbolInfo *symInfo = chainSearch(hashIndex, key);
        return symInfo;
    }



    //Function to delete a key value pair
    bool deleteNode(string key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashFunc1(key);

        if(size==0)
        {
            ///outputFile << "Underflow..\n\n";
            //cout << "Underflow detected..\n" <<endl;
            return NULL;
        }

        SymbolInfo *cur = arr[hashIndex];
        SymbolInfo *prevCur = NULL;
        SymbolInfo *nextCur = NULL;
        //cur = arr[hashIndex];
        if(cur==NULL)
        {
            ///outputFile << "Not Found\n\n";
            //cout << "Not Found\n\n";
            return false;
        }
        prevCur = cur;
        //if current is the starting node...
        if(cur->getName()==key)
        {
            if(cur->next!=NULL)
                nextCur = cur->next;
           /// outputFile << "Found in ScopeTable# " << id << " at position " << hashIndex << ", 0" <<endl << endl;
           /// outputFile << "Deleted entry at " << hashIndex << ", 0 from current Scope Table"  << endl << endl;
            //cout << "Found in ScopeTable# " << id << " at position " << hashIndex << ", 0" <<endl << endl;
            //cout << "Deleted entry at " << hashIndex << ", 0 from current Scope Table"  << endl << endl;
            delete cur;
            arr[hashIndex] = nextCur;
            return true;
        }
        else
        {
            cur = cur->next;
            int tmpCollision = 1;
            while(cur!=NULL)
            {

                if(cur->getName() == key)
                {
                    nextCur = cur->next;

                    //HashNode<K,V> *temp = cur;

                    prevCur->next = nextCur;
                    //Insert free the memory..
                  ///  outputFile << "Found in ScopeTable# " << id << " at position " << hashIndex << ", " << tmpCollision <<endl << endl;
                  ///  outputFile << "Deleted entry at " << hashIndex << ", "<< tmpCollision<< " from current Scope Table"  << endl << endl;
                    //cout << "Found in ScopeTable# " << id << " at position " << hashIndex << ", " << tmpCollision <<endl << endl;
                    //cout << "Deleted entry at " << hashIndex << ", "<< tmpCollision<< " from current Scope Table"  << endl << endl;
                    //cout << "deleting value: "<< cur->getType() << endl;
                    delete cur;

                    // Reduce size
                    size--;
                    return true;
                    //return temp->value;
                }
                prevCur = cur;
                cur = cur->next;
                tmpCollision++;
            }

        }



    }


    //Return current size
    int sizeofMap()
    {
        return size;
    }

    //Return true if size is 0
    bool isEmpty()
    {
        return size == 0;
    }

    //Function to display the stored key value pairs
    void print(FILE *logout)
    {
      ///  outputFile << "ScopeTable# " << id << endl << endl;
	fprintf(logout,"ScopeTable# %d \n", id);
        //cout << "ScopeTable# " << id << endl << endl;

        SymbolInfo *cur;
        for(int i=0 ; i<capacity ; i++)
        {
          ///  outputFile << i << " -->  " ;
            //cout << i << " -->  " ;
	    
            //if(arr[i] != NULL && arr[i]->key != -1)
            if(arr[i] != NULL && arr[i]->getName().compare("-1")!=0)
            {
            fprintf(logout,"%d -->  ", i);
                cur = arr[i];
              ///  outputFile << "< " << cur->getName() << ": " << cur->getType() << " >  ";
                //cout << "< " << cur->getName() << ": " << cur->getType() << " >  ";
                fprintf(logout,"<%s, %s> ", cur->getName().c_str(), cur->getType().c_str() );
                //fprintf(logout,"<%p, %p> ", cur->getName(), cur->getType() );
//                    cout << "key = " << cur->getName()
//                         <<"  value = "<< cur->getType() // << endl;
//                         <<"  index = "<< i+1 <<endl;
                if(cur->next!=NULL)
                {
                    //cout<< "___________chain start___________\n";
                    while(cur->next!=NULL)
                    {
                        cur = cur->next;
                     ///   outputFile << "< " << cur->getName() << ": " << cur->getType() << " >  ";
                        //cout << "< " << cur->getName() << ": " << cur->getType() << " >  ";
                        fprintf(logout,"<%s, %s> ", cur->getName().c_str(), cur->getType().c_str() );
                        //fprintf(logout,"<%p, %p> ", cur->getName(), cur->getType() );
//                            cout << "key = " << cur->getName()
//                                 <<"  value = "<< cur->getType() << endl;
                        //<<"  index = "<< i+1 << endl;

                    }
                    //cout<<"............chain End............\n\n";
                }
            fprintf(logout,"\n");
            }
         ///   outputFile << endl << endl;
            //cout << endl << endl;
	//logout = outputFile;
        }
	fprintf(logout,"\n");
    }


};

//ScopeTable *head;

class SymbolTable
{
    ScopeTable *curScope = NULL ;
    int capacity;

public:

    void setCapacity(int n)
    {
        capacity = n;
        curScope = new ScopeTable(capacity);
        //enterScope();
    }
	
    void enterScope()
    {
        ScopeTable *newScope = new ScopeTable(capacity);
        ScopeTable *tmp = curScope;
        curScope = newScope;
        if(tmp!=NULL)
        {
            curScope->parentScope = tmp;
            curScope->id = curScope->parentScope->id + curScope->parentScope->exited;
            //fprintf(fp, "New ScopeTable with id %d created\n", curScope->id);
            //fp << "New ScopeTable with id " << curScope->id << " created\n";
          ///  outputFile << "New ScopeTable with id " << curScope->id << " created\n\n";
            //cout << "New ScopeTable with id " << curScope->id << " created\n\n";
        }
    }
    void enterScope(FILE *fp)
    {
        ScopeTable *newScope = new ScopeTable(capacity);
        ScopeTable *tmp = curScope;
        curScope = newScope;
        if(tmp!=NULL)
        {
            curScope->parentScope = tmp;
            curScope->exited = curScope->parentScope->exited;
            curScope->id = curScope->parentScope->id  + curScope->parentScope->exited;
            
            fprintf(fp, "New ScopeTable with id %d created\n", curScope->id);
            //fp << "New ScopeTable with id " << curScope->id << " created\n";
          ///  outputFile << "New ScopeTable with id " << curScope->id << " created\n\n";
            //cout << "New ScopeTable with id " << curScope->id << " created\n\n";
        }
    }
    void exitScope(FILE *fp)
    {
        if(curScope==NULL)
        {
          ///  outputFile << "Scope Empty..\n" <<endl;
            //cout<< "Scope Empty..\n" <<endl;
            //fprintf(fp, "Scope Empty..\n");
            return;
        }
        if(curScope->parentScope!=NULL)
        {
            ScopeTable *tmp = curScope;
            curScope = curScope->parentScope;
            fprintf(fp, "ScopeTable with id %d removed\n", tmp->id, curScope->id);
          ///  outputFile << "ScopeTable with id " << tmp->id << " removed\n\n";
            //cout << "ScopeTable with id " << tmp->id << " removed\n\n";
            delete tmp;
            curScope->exited++;
        }
        else
        {
          ///  outputFile << "ScopeTable with id " << curScope->id << " removed\n\n";
            //cout << "ScopeTable with id " << curScope->id << " removed\n\n";
            fprintf(fp, "ScopeTable with id %d removed\n", curScope->id);
            delete curScope;
        }
        
    }
    bool insert(string key, string value, FILE *fp)
    {
        
        //fprintf(fp, "Inserted at %d : %s , %s\n", curScope->id,  key.c_str(), value.c_str());
        return curScope->insertNode(key, value);
//        if(curScope->insertNode(key, value))
//        {
//            cout << "Inserted in ScopeTable#" << curScope->id
//            return true;
//        }
//        else
//        {
//            return false;
//        }
    }
    bool remove(string key)
    {
        return curScope->deleteNode(key);
//        if(curScope->deleteNode(key))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
    }
    SymbolInfo *lookUp(string key)
    {

        SymbolInfo *tmp = curScope->lookUp(key);
        ScopeTable *cur = curScope;
        //printf("searching in scope: %d\n",cur->id);
        while(!tmp->getName().compare("-1") && cur->parentScope!=NULL)
        {
            
            cur = cur->parentScope;
            tmp = cur->lookUp(key);
            //printf("searching in scope: %d\n",cur->id);
        }
        if(tmp==NULL || !tmp->getName().compare("-1"))
        {
           /// outputFile << "Not Found.\n\n";
            //cout << "Not Found. " << key <<"\n\n";
        }
        //edited 19june 2018
        /*SymbolInfo *tmp = curScope->lookUp(key);
        while(tmp==NULL && curScope->parentScope!=NULL)
        {
            curScope = curScope->parentScope;
            tmp = curScope->lookUp(key);
        }
        if(tmp==NULL || tmp->getName().compare("-1"))
        {
           /// outputFile << "Not Found.\n\n";
            cout << "Not Found.\n\n";
        }*/
        return tmp;
    }
    SymbolInfo *lookUpCur(string key)
    {
    	SymbolInfo *tmp = curScope->lookUp(key);
        if(tmp==NULL || !tmp->getName().compare("-1"))
        {
           /// outputFile << "Not Found.\n\n";
            //cout << "Not Found. " << key <<"\n\n";
        }
        return tmp;
    }

    void printCurScope(FILE *logout)
    {
        curScope->print(logout);
    }

    void printAllScope(FILE *logout)
    {
        int i=0;
        ScopeTable *cur = curScope;
        while(cur!=NULL)
        {
            //cout << i << " :  \n";

            cur->print(logout);
          ///  outputFile << endl << endl;
            //cout << endl << endl;
            fprintf(logout,"\n");
            i++;
            if(cur->parentScope == NULL)
                return;
            cur = cur->parentScope;
         ///   outputFile << endl << endl;
            //cout << endl << endl;
            fprintf(logout,"\n");
        }
    }




};

/*
int main()
{
    ifstream inputFile;
    //ofstream outputFile;
    inputFile.open("input.txt");
    outputFile.open("output.txt");
    int n;
    inputFile >> n;
    SymbolTable *sym = new SymbolTable;
    sym->setCapacity(n);
    char ch;
    while(inputFile >> ch)
    {
        string key, value;

        //cin >> ch;

        ch = toupper(ch);
        if(ch=='I')
        {
            // cout << ch << endl;
            //cin >> key >> value;
            inputFile >> key;
            inputFile >> value;
            sym->insert(key, value);
            //cout << sym->insert(key, value) << endl;
            //cout << "after insert\n";
        }
        else if(ch=='L')
        {
            //cin >> key;
            inputFile >> key;
            sym->lookUp(key);
        }
        else if(ch == 'D')
        {
            inputFile >> key;
            sym->remove(key);
        }
        else if(ch=='P')
        {
            char c;
            inputFile >> c;
            c = toupper(c);
            if(c=='A')
            {
                sym->printAllScope();
            }
            else if(c=='C')
            {
                sym->printCurScope();
            }
        }
        else if(ch=='S')
        {
            sym->enterScope();
        }
        else if(ch=='E')
        {
            sym->exitScope();
        }
    }
    inputFile.close();
    outputFile.close();

} */
