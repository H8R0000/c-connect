#include "connect.h"


int main()
{
    try
    {

        add_st();
        delete_st();
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
