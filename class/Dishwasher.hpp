#ifndef Dishwasher_h
#define Dishwasher_h
#ifndef ConsoleView_h
#include "ConsoleView.hpp"
#endif
class Dishwasher
{
private:
    Controler* controler;
    ConsoleView* view;


public:
    bool working;
    void selectProgram();
    int confirm();
    void run(ConsoleView* v);
    bool progress() ;
    void refresh();
    Dishwasher(){};
    ~Dishwasher(){};
    
};

void Dishwasher::run(ConsoleView* v) {
    
        this->working = false;
        this->view = v;
        this->controler = new Controler();
        while(true) {
            this->view->showControler(this->controler);
            this->selectProgram();
            this->view->showProgram(this->controler->currentProgram);
            int c = this->confirm();
            if(c > 0)
                while(this->progress()) { }
            else if(c = 0) {
                break;
            }
            this->working = false;
            this->refresh();
        }
        
        
    
}

bool Dishwasher::progress() {
    
        this->working = true;
        //simulation of working dishwasher
        std::cout << "working...." << std::endl;
        Sleep(1000);
        std::cout << "working...." << std::endl;
        Sleep(1000);
        std::cout << "still working!" << std::endl;
        Sleep(500);
        std::cout << "BE PATIENT" << std::endl;
        Sleep(1000);
        std::cout << "almost done" << std::endl;
        Sleep(1000);
        std::cout << "aaaand ... DONE" << std::endl;
        Sleep(1500);

        return false;
    
}

int Dishwasher::confirm() {
    int c = this->view->confirm();
    return c;
    return false;
}

void Dishwasher::refresh()
{
    this->controler->currentProgram = nullptr;
}

void Dishwasher::selectProgram() {
    Program* selected;
    selected = this->view->selectProgram(controler->programs);
    this->controler->setProgram(selected);
}


#endif

