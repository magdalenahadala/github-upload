#ifndef Program_h
#define Program_h
class Program
{
    
public:
    std::string name;
    int length;
    int temperature;
    int energy;
    
    Program(std::string a, int b, int c, int d) {
        name = a;
        length = b;
        temperature = c;
        energy = d;
    };
    ~Program();
    
};



#endif
