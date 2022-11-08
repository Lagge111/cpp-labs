
#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
public:
    Connection();
    ~Connection();
    double setVoltage(double v);
    double getVoltage();

private:
    double voltage;
};

#endif