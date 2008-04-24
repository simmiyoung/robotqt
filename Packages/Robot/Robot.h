#include <vector>

class Robot {
    public:
        unsigned short int getRodaSize();
        unsigned short int setRodaSize(unsigned short int cm);
        char * getName();
        unsigned short int getId();
        void setMotor(Motor motor);
        Motor * getMotor(unsigned short int Id);
        void setSensor(Sensor sensor);
        Motor * getSensor(unsigned short int Id);

    private:
        unsigned short int Id;
        unsigned short int RodaSize;
        char * Name;
        
        Vector<Motor> Motors;
        Vector<Sensor> Sensors;

        //unsigned short int Degree;
        //short int posX;
        //short int posY;
};
