#ifndef ACCOUNT_H
#define ACCOUNT_H

class WorkPacket {
    private:
        int id;
    public:
        WorkPacket(int id):id(id){};
        const int getId(){
          return this->id;
        };

}

#endif
