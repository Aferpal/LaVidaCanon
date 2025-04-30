#pragma once
#include "DataBaseConnection.h"
#include <mysql-cppconn/mysqlx/xdevapi.h>

namespace lvc
{
    class DataBaseMysql : public DataBaseConnection{
        private:
            std::string user;

            std::string password;

            std::string dbName;

            mysqlx::abi2::Session* session;

            mysqlx::abi2::Schema* db;
            
            bool isConnected;

            void disconnect();

        public:

            DataBaseMysql(const std::string&, const std::string&, const std::string&);
            
            void connect() override;

            void selectProgramas(List<Programa>*) override;

            bool insertPrograma(const Programa&) override;

            bool updatePrograma(const Programa&) override;

            bool deletePrograma(const Programa&) override;

            ~DataBaseMysql();
    };
} // namespace lvc
