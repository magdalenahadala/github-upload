#ifndef Controler_h
#define Controler_h


class Controler
{
private:
public:
    Program* currentProgram;
    std::list<Program*> programs;
    
    Controler() {
        this->loadPrograms();
    };
    ~Controler();
    void setProgram(Program * a);
    void loadPrograms() ;
    
};

void Controler::loadPrograms() {
    {
        int b,c,d;
        std::string a;
        std::string path = "C:\\Users\\magda\\OneDrive\\Pulpit\\dishwasher\\class\\programs\\";
        std::string filepath;
        for(int i = 0; i<1024; i++) {
            filepath = path;
            filepath += std::to_string(i);
            filepath += ".txt";
            std::ifstream infile(filepath);
            if(infile.is_open()) {
                std::cout <<"Loaded program:"<< filepath << std::endl;
   					infile >> a >> b >> c >> d ;
                	std::cout << a;
                    Program* p = new Program(a, b, c, d);
                    programs.push_back(p);
                
            }
        }
        
        
        
    }
}

void Controler::setProgram(Program* a) {
    
        this->currentProgram = a;
    
}

#endif
