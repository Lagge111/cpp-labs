
#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
public:
    Connection();
    ~Connection();
    void setVoltage(double const v);
    double getVoltage();

private:
    double voltage;
};

#endif