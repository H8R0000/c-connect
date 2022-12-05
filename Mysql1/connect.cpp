#include "connect.h"

void fetchAll_st()
{

    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std:string table = "student";
    cout << "Working with table: " << table << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);


    // Accessing an existing table
    Table myTable = myDb.getTable(table);

    // Find a row in the SQL Table
    RowResult myRows = myTable.select("id_st", "name", "surname", "patronymic", "st", "alive", "id_group").execute();

    for (Row row : myRows.fetchAll())
    {
        cout << "ID:" << row[0] << "\t";
        cout << "Name:" << row[1] << "\t";
        cout << "Surname:" << row[2] << "\t";
        cout << "Patronymic:" << row[3] << "\t";
        cout << "St:" << row[4] << "\t";
        cout << "alive?:" << bool(row[5]) << "\t";
        cout << "id_group:" << row[6] << endl;

    }

}
void fetchAll_teachers()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std:string table = "teacher";
    cout << "Working with table: " << table << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);


    // Accessing an existing table
    Table myTable = myDb.getTable(table);

    // Find a row in the SQL Table
    RowResult myRows = myTable.select("id_t", "name", "surname").execute();

    for (Row row : myRows.fetchAll())
    {
        cout << "ID:" << row[0] << "\t";
        cout << "Name:" << row[1] << "\t";
        cout << "Surname:" << row[2] << endl;
    }
}
void fetchAll_labs()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "laba";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    RowResult myRows = myTable.select("id_laba", "name", "id_block").execute();

    for (Row row : myRows.fetchAll())
    {
        cout << "ID_LABA:" << row[0] << "\t";
        cout << "Name:" << row[1] << "\t";
        cout << "ID_BLOCK:" << row[2] << endl;
    }
}
void fetchAll_groups()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "group";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    RowResult myRows = myTable.select("id_g", "YearForm", "id_spec").execute();

    for (Row row : myRows.fetchAll())
    {
        cout << "id_g:" << row[0] << "\t";
        cout << "YearForm:" << row[1] << "\t";
        cout << "id_spec:" << row[2] << endl;
    }
}


void add_st()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std:string table_str = "student";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);
    Table help1Table = myDb.getTable("group");
    Table help2Table = myDb.getTable("spec");

    std::string name, surname, patronymic, st;
    int alive, id_group;

    bool a{ true };
    while (a)
    {
        cout << "Enter NAME: ";
        std::cin >> name;
        cout << "Enter SURNAME: ";
        std::cin >> surname;
        cout << "Enter PATRONYMIC: ";
        std::cin >> patronymic;
        cout << "Enter ST: ";
        std::cin >> st;
        cout << "Is he ALIVE?, type 1=true or 0=false: ";
        std::cin >> alive;

        RowResult myRows1 = help1Table.select("id_g", "YearForm","id_spec").execute();
        RowResult myRows2 = help2Table.select("idspec", "name").execute();

        cout << "For info: " << endl;
        for (Row row : myRows2.fetchAll())
        {
            cout << "id_spec " << row[0] << " stands for " << row[1] << endl;;
        }
        cout << endl;

        cout << "For info: " << endl;
        for (Row row : myRows1.fetchAll())
        {
            cout << "id_g " << row[0] << " stands for " << row[1] << "year of formation  and " << \
                row[2] << "for id_spec" << endl;

        }


        cout << "Enter ID_GROUP: ";
        std::cin >> id_group;

        // Find a row in the SQL Table
        myTable.insert("name", "surname", "patronymic", "st", "alive", "id_group")
            .values(name, surname, patronymic, st, alive, id_group)
            .execute();

        cout << "Enter one more? print [y/n]: ";
        char answ;
        std::cin >> answ;
        if (answ == 'y')
            a = true;
        else if (answ == 'n')
            a = false;
        else if (answ != 'n' and answ != 'y')
        {
            cout << "Wrong input! Exiting..." << endl;
            a = false;
        }
    }
}
void add_t()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "teacher";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    std::string name, surname;

    bool a{ true };
    while (a)
    {
        cout << "Enter NAME: ";
        std::cin >> name;
        cout << "Enter SURNAME: ";
        std::cin >> surname;


        // Find a row in the SQL Table
        myTable.insert("name", "surname")
            .values(name, surname)
            .execute();
        cout << "Enter one more? print [y/n]: ";
        char answ;
        std::cin >> answ;
        if (answ == 'y')
            a = true;
        else if (answ == 'n')
            a = false;
        else if (answ != 'n' and answ != 'y')
        {
            cout << "Wrong input! Exiting..." << endl;
            a = false;
        }
    }
}
void add_group()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "group";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);
    Table helpTable = myDb.getTable("spec");

    bool a{ true };
    while (a)
    {
        int YearForm, id_spec;
        cout << "Enter year of formation : ";
        std::cin >> YearForm;
        RowResult myRows = helpTable.select("idspec", "name").execute();
        cout << "For info: " << endl;
        for (Row row : myRows.fetchAll())
        {
            cout << "id_spec " << row[0] << " stands for " << row[1] << endl;;
        }
        cout << "Enter id_spec: ";
        std::cin >> id_spec;

        // Find a row in the SQL Table
        myTable.insert("YearForm", "id_spec")
            .values(YearForm, id_spec)
            .execute();

        cout << "Enter one more? print [y/n]: ";
        char answ;
        std::cin >> answ;
        if (answ == 'y')
            a = true;
        else if (answ == 'n')
            a = false;
        else if (answ != 'n' and answ != 'y')
        {
            cout << "Wrong input! Exiting..." << endl;
            a = false;
        }


    }
}
void add_lab()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "laba";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);
    Table helpTable = myDb.getTable("block_l");

    bool a{ true };
    while (a)
    {
        int id_block;
        std::string name{};

        cout << "Enter lab's name(skipable) : ";
        std::cin >> name;
        RowResult myRows = helpTable.select("idblock_l", "name").execute();
        cout << "For info: " << endl;
        for (Row row : myRows.fetchAll())
        {
            cout << "id_block " << row[0] << " stands for " << row[1] << endl;;
        }
        cout << "Enter id_block: ";
        std::cin >> id_block;

        // Find a row in the SQL Table
        myTable.insert( "name", "id_block")
            .values(name, id_block)
            .execute();

        cout << "Enter one more? print [y/n]: ";
        char answ;
        std::cin >> answ;
        if (answ == 'y')
            a = true;
        else if (answ == 'n')
            a = false;
        else if (answ != 'n' and answ != 'y')
        {
            cout << "Wrong input! Exiting..." << endl;
            a = false;
        }
    }
}


void delete_lab()
{

    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "laba";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    cout << "For info" << endl;
    fetchAll_labs();

    std::string id{};
    cout << "Enter LAB's ID to be removed: ";
    std::cin >> id;


    // Find a row in the SQL Table
    myTable.remove().where("id_laba = " + id).execute();
}
void delete_st()
{

    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "student";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    cout << "For info" << endl;
    fetchAll_st();

    std::string id{};
    cout << "Enter STUDENT's ID to be removed: ";
    std::cin >> id;


    // Find a row in the SQL Table
    myTable.remove().where("id_st = " + id).execute();
}
void delete_t()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "teacher";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    cout << "For info" << endl;
    fetchAll_teachers();

    std::string id{};
    cout << "Enter TEACHER's ID to be removed: ";
    std::cin >> id;


    // Find a row in the SQL Table
    myTable.remove().where("id_t = " + id).execute();
}
void delete_group()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "group";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    cout << "For info" << endl;
    fetchAll_groups();

    std::string id{};
    cout << "Enter GROUP's ID to be removed: ";
    std::cin >> id;


    // Find a row in the SQL Table
    myTable.remove().where("id_g = " + id).execute();
}