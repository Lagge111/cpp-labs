#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
public:
    Connection();
    ~Connection();
    void setVoltage(double v);
    double getVoltage();

private:
    double voltage;
};

#endif