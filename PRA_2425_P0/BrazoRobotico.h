
class BrazoRobotico {
private:
    double x, y, z;
    int sujeto;   

public:
    // Constructor
    BrazoRobotico(double x, double y, double z);

    // Métodos consultores
    double getX();
    double getY();
    double getZ();
    int EstaSujeto();

    // Métodos de comportamiento
    void coger();
    void soltar();
    void mover(double dx, double dy, double dz);
};

