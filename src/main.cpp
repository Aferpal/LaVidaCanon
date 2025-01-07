#include "./App/App.h"

int main(){

    lvc::DataBaseConnection* db = new lvc::DataBaseTXT{"/home/abel_uma/projects/LaVidaCañon/db"};

    lvc::App app {db};

    return 0;
}