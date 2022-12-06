#include "connect.h"


int main()
{
    try
    {

        student karim{ "Karim", "Niggmatulin", "Rinatovich", "st066970",1,2 };
        teacher teach{ "Tayler","Derden" };
        laba do5{ "do5",3 };
        group GR2018{ 2018,2 };

        add_group(GR2018);
        fetchAll_groups();
        std::string id;
        std::cin >> id;
        delete_group(id);


    }
    catch (const mysqlx::Error& err)
    {
        cout << "ERROR: " << err << endl;
        return 1;
    }
    catch (std::exception& ex)
    {
        cout << "STD EXCEPTION: " << ex.what() << endl;
        return 2;
    }
    catch (const char* ex)
    {
        cout << "EXCEPTION: " << ex << endl;
        return 3;
    }
}
