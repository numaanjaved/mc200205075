//Question no 17
//xvii.	Given the Periodic table below, generate all possible combination of chemicals which are having atomic number greater than their immediate below chemical by difference of 15 to 20% at max, to the right the difference should not be more than 20% from that of immediately below and 10% at max from the difference from the left. All those chemicals should be displayed in sequence with increasing sum of atomic number of chemical created.


#include<iostream>
#include<stdio.h>
#include<string>
#include<iomanip>
using namespace std;

class Element{
    public:
        static int count;
        int number;
        string name;
        string symbol;
        int atomicNumber;
        int group;
        int period;
        bool exists = false;
        Element(string name, string symbol, int atomicNumber){
            ++Element::count;
            setNumber(Element::count);
            this->setName(name);
            this->setSymbol(symbol);
            this->setAtomicNumber(atomicNumber);
            this->setPeriod();
            this->setGroup();  
            this->exists = true;                     
        }
        void setNumber(int aNumber){
            this->number = aNumber;
        }
        int getNumber(){
            return this->number;
        }
        void setName(string aName){
            this->name = aName;
        }
        string getname(){
            return this->name;
        }
        void setSymbol(string aSymbol){
            this->symbol = aSymbol; 
        }
        string getSymbol(){
            return this->symbol;
        }
        void setAtomicNumber(int aAtomicNumber){
            this->atomicNumber = aAtomicNumber;
        }
        int getAtomicNumber(){
            return this->atomicNumber;
        }
        void setGroup(){
            int placement = 0;
            if(this->period == 0){
                placement = this->atomicNumber - 1;
                if(placement < 1){
                    this->group = placement;
                }
                else{
                    this->group = placement+30;
                }
            }
            else if(this->period == 1){
                placement = this->atomicNumber - 3;
                if(placement < 2){
                    this->group = placement;
                }
                else{
                    this->group = placement+24;
                }
            }
            else if(this->period == 2){
                placement = this->atomicNumber - 11;
                if(placement < 2){
                    this->group = placement;
                }
                else{
                    this->group = placement+24;
                }
            }
            else if(this->period == 3){
                placement = this->atomicNumber - 19;
                if(placement < 2){
                    this->group = placement;
                }
                else{
                    this->group = placement+14;
                }
            }
            else if(this->period == 4){
                placement = this->atomicNumber - 37;
                if(placement < 2){
                    this->group = placement; 
                }
                else{
                    this->group = placement+14;
                }
            }
            else if(this->period == 5){
                placement = this->atomicNumber - 55;
                this->group = placement;
            }
            else if(this->period == 6){
                placement = this->atomicNumber - 87;
                this->group = placement;
            }
        }
        int getGroup(){
            return this->group;
        }
        void setPeriod(){
            if(this->atomicNumber <= 2){
                this->period = 0;
            }
            else if(this->atomicNumber <= 10){
                this->period = 1;
            }
            else if(this->atomicNumber <= 18){
                this->period = 2;
            }
            else if(this->atomicNumber <= 36){
                this->period = 3;
            }
            else if(this->atomicNumber <= 54){
                this->period = 4;
            }
            else if(this->atomicNumber <= 86){
                this->period = 5;
            }
            else if(this->atomicNumber <= 118){
                this->period = 6;
            } 
        }
        int getPeriod(){
            return this->period;
        }
        void display(){
            cout << this->number << ". " << this->name << " " << this->symbol << " " << this->atomicNumber << " " << this->period << " " << this->group << endl;
        }
};
int Element::count = 0;

class PeriodicTable{
    public:
        Element* elements[118];
        Element* group[32][7];
        Element* period[7][32];

        PeriodicTable(){
            this->setElements();
        }
        void setElements(){
            this->elements[0] = new Element("Hydrogen", "H", 1);
            this->elements[1] = new Element("Helium", "He", 2);
            this->elements[2] = new Element("Lithium", "Li", 3);
            this->elements[3] = new Element("Beryllium", "Be", 4);
            this->elements[4] = new Element("Boron", "B", 5);
            this->elements[5] = new Element("Carbon", "C", 6);
            this->elements[6] = new Element("Nitrogen", "N", 7);
            this->elements[7] = new Element("Oxygen", "O", 8);
            this->elements[8] = new Element("Fluorine", "F", 9);
            this->elements[9] = new Element("Neon", "Ne", 10);
            this->elements[10] = new Element("Sodium", "Na", 11);
            this->elements[11] = new Element("Magnesium", "Mg", 12);
            this->elements[12] = new Element("Aluminium", "Al", 13);
            this->elements[13] = new Element("Silicon", "Si", 14);
            this->elements[14] = new Element("Phosphorus", "P", 15);
            this->elements[15] = new Element("Sulfur", "S", 16);
            this->elements[16] = new Element("Chlorine", "Cl", 17);
            this->elements[17] = new Element("Argon", "Ar", 18);
            this->elements[18] = new Element("Potassium", "K", 19);
            this->elements[19] = new Element("Calcium", "Ca", 20);
            this->elements[20] = new Element("Scandium", "Sc", 21);
            this->elements[21] = new Element("Titanium", "Ti", 22);
            this->elements[22] = new Element("Vanadium", "V", 23);
            this->elements[23] = new Element("Chromium", "Cr", 24);
            this->elements[24] = new Element("Manganese", "Mn", 25);
            this->elements[25] = new Element("Iron", "Fe", 26);
            this->elements[26] = new Element("Cobalt", "Co", 27);
            this->elements[27] = new Element("Nickel", "Ni", 28);
            this->elements[28] = new Element("Copper", "Cu", 29);
            this->elements[29] = new Element("Zinc", "Zn", 30);
            this->elements[30] = new Element("Gallium", "Ga", 31);
            this->elements[31] = new Element("Germanium", "Ge", 32);

            this->elements[32] = new Element("Arsenic", "As", 33);
            this->elements[33] = new Element("Selenium", "Se", 34);
            this->elements[34] = new Element("Bromine", "Br", 35);
            this->elements[35] = new Element("Krypton", "Kr", 36);
            this->elements[36] = new Element("Rubidium", "Rb", 37);
            this->elements[37] = new Element("Strontium", "Sr", 38);
            this->elements[38] = new Element("Yttrium", "Y", 39);
            this->elements[39] = new Element("Zirconium", "Zr", 40);
            this->elements[40] = new Element("Niobium", "Nb", 41);
            this->elements[41] = new Element("Molybdenium", "Mo", 42);
            this->elements[42] = new Element("Technetium", "Tc", 43);
            this->elements[43] = new Element("Ruthenium", "Ru", 44);
            this->elements[44] = new Element("Rhodium", "Rh", 45);
            this->elements[45] = new Element("Palladium", "Pd", 46);
            this->elements[46] = new Element("Silver", "Ag", 47);
            this->elements[47] = new Element("Cadmium", "Cd", 48);
            this->elements[48] = new Element("Indium", "In", 49);
            this->elements[49] = new Element("Tin", "Sn", 50);
            this->elements[50] = new Element("Antimony", "Sb", 51);
            this->elements[51] = new Element("Tellurium", "Te", 52);
            this->elements[52] = new Element("Iodine", "I", 53);
            this->elements[53] = new Element("Xenon", "Xe", 54);
            this->elements[54] = new Element("Cesium", "Cs", 55);
            this->elements[55] = new Element("Barium", "Ba", 56);
            this->elements[56] = new Element("Lanthanum", "La", 57);
            this->elements[57] = new Element("Cerium", "Ce", 58);
            this->elements[58] = new Element("Praseodymium", "Pr", 59);
            this->elements[59] = new Element("Neodymium", "Nd", 60);
            this->elements[60] = new Element("Promethium", "Pm", 61);
            this->elements[61] = new Element("Samarium", "Sm", 62);
            this->elements[62] = new Element("Europium", "Eu", 63);
            this->elements[63] = new Element("Gadolinium", "Gd", 64);

            this->elements[64] = new Element("Terbium", "Tb", 65);
            this->elements[65] = new Element("Dysprosium", "Dy", 66);
            this->elements[66] = new Element("Holmium", "Ho", 67);
            this->elements[67] = new Element("Erbium", "Er", 68);
            this->elements[68] = new Element("Thulium", "Tm", 69);
            this->elements[69] = new Element("Ytterbium", "Yb", 70);
            this->elements[70] = new Element("Lutetium", "Lu", 71);
            this->elements[71] = new Element("Hafnium", "Hf", 72);
            this->elements[72] = new Element("Tantalum", "Ta", 73);
            this->elements[73] = new Element("Tungsten", "W", 74);
            this->elements[74] = new Element("Rhenium", "Re", 75);
            this->elements[75] = new Element("Osmium", "Os", 76);
            this->elements[76] = new Element("Iridium", "Ir", 77);
            this->elements[77] = new Element("Platinum", "Pt", 78);
            this->elements[78] = new Element("Gold", "Au", 79);
            this->elements[79] = new Element("Mercury", "Hg", 80);
            this->elements[80] = new Element("Thallium", "Tl", 81);
            this->elements[81] = new Element("Lead", "Pb", 82);
            this->elements[82] = new Element("Bismuth", "Bi", 83);
            this->elements[83] = new Element("Polonium", "Po", 84);
            this->elements[84] = new Element("Astatine", "At", 85);
            this->elements[85] = new Element("Radon", "Rn", 86);
            this->elements[86] = new Element("Francium", "Fr", 87);
            this->elements[87] = new Element("Radium", "Ra", 88);
            this->elements[88] = new Element("Actinium", "Ac", 89);
            this->elements[89] = new Element("Thorium", "Th", 90);
            this->elements[90] = new Element("Protactinium", "Pa", 91);
            this->elements[91] = new Element("Uranium", "U", 92);
            this->elements[92] = new Element("Neptunium", "Np", 93);
            this->elements[93] = new Element("Plutonium", "Pu", 94);
            this->elements[94] = new Element("Americium", "Am", 95);
            this->elements[95] = new Element("Curium", "Cm", 96);

            this->elements[96] = new Element("Berkelium", "Bk", 97);
            this->elements[97] = new Element("Californium", "Cf", 98);
            this->elements[98] = new Element("Einsteinium", "Es", 99);
            this->elements[99] = new Element("Fermium", "Fm", 100);
            this->elements[100] = new Element("Mendelevium", "Md", 101);
            this->elements[101] = new Element("Nobelium", "No", 102);
            this->elements[102] = new Element("Lawrencium", "Lr", 103);
            this->elements[103] = new Element("Rutherfordium", "Rf", 104);
            this->elements[104] = new Element("Dubnium", "Db", 105);
            this->elements[105] = new Element("Seaborgium", "Sg", 106);
            this->elements[106] = new Element("Bohrium", "Bh", 107);
            this->elements[107] = new Element("Hassium", "Hs", 108);
            this->elements[108] = new Element("Meitnerium", "Mt", 109);
            this->elements[109] = new Element("Darmstadium", "Ds", 110);
            this->elements[110] = new Element("Roentgenium", "Rg", 111);
            this->elements[111] = new Element("Copernicium", "Cn", 112);
            this->elements[112] = new Element("Nihonium", "Uut", 113);
            this->elements[113] = new Element("Flerovium", "Fl", 114);
            this->elements[114] = new Element("Moscovium", "Uup", 115);
            this->elements[115] = new Element("Livermorium", "Lv", 116);
            this->elements[116] = new Element("Tennessine", "Uus", 117);
            this->elements[117] = new Element("Oganesson", "Uuo", 118);
        }
        void pushGroup(){
            for(int i = 0; i < 118; ++i){
                //this->elements[i]->display();
                if(this->elements[i] != NULL){
                    for(int j = 0; j < 32; ++j){
                        for(int k = 0; k < 7; ++k){
                            if(j == this->elements[i]->group && k == this->elements[i]->period){ 
                                //this->elements[i]->display();                               
                                this->group[j][k] = this->elements[i];
                            }
                        }                        
                    }  
                }
            }
        }
        void pushPeriod(){
            for(int i = 0; i < 118; ++i){
                //this->elements[i]->display();
                if(this->elements[i] != NULL){
                    for(int j = 0; j < 7; ++j){
                        for(int k = 0; k < 32; ++k){
                            if(j == this->elements[i]->period && k == this->elements[i]->group){
                                this->period[j][k] = this->elements[i];
                            }
                        }
                        
                    }  
                }
            }
        }
        int sum(int i){
            int sum1 = this->elements[i]->getAtomicNumber();
            int sum2 = this->elements[i+1]->getAtomicNumber();
            int sum3 = this->elements[i - 1]->getAtomicNumber();

            return sum1 + sum2 + sum3;
        }
        Element* elementBelow(int i){
            return this->elements[i - 1];
        }
        Element* elementAbove(int i){
            return this->elements[i + 1];
        }
};
int main(){
    PeriodicTable* table = new PeriodicTable();
    //table->display(); 
    table->pushGroup();
    table->pushPeriod();
    int atomicNumber;
    int belowAtomicNumber;
    int leftBelowAtomicNumber;
    int rightAtomicNumber;
    bool greaterThan;
    bool leftMoreThan;
    bool rightMoreThan;
    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < 32; ++j){
            if(table->period[i][j] != NULL){
               cout << setw(6) << table->period[i][j]->getSymbol();
            }
            else{
                cout << setw(6) << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    int totalNumberOfElements = 0;
    for(int i = 2; i < Element::count - 2; ++i){
            atomicNumber = table->elements[i]->getAtomicNumber();
            belowAtomicNumber = table->elements[i - 1]->getAtomicNumber();
            leftBelowAtomicNumber = table->elementBelow(i - 1)->getAtomicNumber();
            rightAtomicNumber = table->elementAbove(i)->getAtomicNumber();
            rightMoreThan = (atomicNumber - belowAtomicNumber) < 0.2 * atomicNumber;
            leftMoreThan = (belowAtomicNumber - leftBelowAtomicNumber) < 0.1 * atomicNumber;
            greaterThan = (atomicNumber - belowAtomicNumber) > 0.2 * atomicNumber || (atomicNumber - belowAtomicNumber) > 0.15 * atomicNumber;
            //If it is And
            if(greaterThan && rightMoreThan && leftMoreThan){
                cout << table->elements[i]->getname() << endl;
                cout << "Sum of Atomic Numbers of 3 Elements: " << table->sum(i) << endl;
                ++totalNumberOfElements;
            }
            //if it is OR
            // if(greaterThan || rightMoreThan || leftMoreThan){
            //     cout << table->elements[i]->getname() << endl;
            //     cout << "Sum of Atomic Numbers of 3 Elements: " << table->sum(i) << endl;
            //     ++totalNumberOfElements;
            // }
            // table->elementBelow(i)->display();
            // table->elementAbove(i)->display();
            
            
    }

    cout << endl << "Total Number of Elements in immediate below: "<< totalNumberOfElements;
    
    return 0;
}