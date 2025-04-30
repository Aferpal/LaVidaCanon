#include "./DataBaseMysql.h"
#include<iostream>
using namespace lvc;
using namespace ::mysqlx;

DataBaseMysql::DataBaseMysql(const std::string& user, const std::string& password, const std::string& dbName): user{user}, password{password}, dbName{dbName}, isConnected{false}{}

void DataBaseMysql::connect(){
    try{
        std::string url = "mysqlx://"+this->user+":"+this->password+"@127.0.0.1";
        this->session = new Session(url.c_str());
        this->db = new Schema(this->session->getSchema(this->dbName, true));
        this->isConnected = true;
    }catch(const std::exception& x){
        std::cerr<<x.what()<<'\n';
        this->session = nullptr;
        this->db = nullptr;
        this->isConnected = false;
        throw 0;
    }
}


void DataBaseMysql::selectProgramas(List<Programa>* res){
    Table programa = this->db->getTable("PROGRAMA", true);
    res->clear();
    std::vector<Row> rows = programa.select().execute().fetchAll();
    for(Row& r : rows){
        res->append(Programa(r.get(0).get<std::string>(), r.get(1).get<std::string>()));
    }
}

/*void DataBaseMysql::selectProgramaById(int id){
    Table programa = this->db->getTable("PROGRAMA", true);
    res->clear();
    std::vector<Row> rows = programa.select().where("id = "+id).execute().fetchAll();
    for(Row& r : rows){
        res->append(Programa(r.get(0).get<std::string>(), r.get(1).get<std::string>()));
    }
}*/

bool DataBaseMysql::insertPrograma(const Programa& p){
    Table programa = this->db->getTable("PROGRAMA", true);
    Row insertionRow;
    insertionRow.set(0, p.getNombre());
    insertionRow.set(1, p.getDirectorio());
    insertionRow.set(2, Value());
    insertionRow.set(3, Value());
    return programa.insert().values(insertionRow).execute().getAffectedItemsCount() == 1;
}

bool DataBaseMysql::updatePrograma(const Programa& p){
    Table programa = this->db->getTable("PROGRAMA", true);
    Row insertionRow;
    insertionRow.set(0, p.getNombre());
    insertionRow.set(1, p.getDirectorio());
    insertionRow.set(2, Value());
    insertionRow.set(3, Value());
    return programa.insert().values(insertionRow).execute().getAffectedItemsCount() == 1;
}

bool DataBaseMysql::deletePrograma(const Programa& p){
    Table programa = this->db->getTable("PROGRAMA", true);
    return programa.remove().where("nombre='"+p.getNombre()+"'").execute().getAffectedItemsCount() == 1;
}

DataBaseMysql::~DataBaseMysql(){
    this->session->close();
}