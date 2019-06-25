# Enviroment
Windows 10
Microsoft Visual Studio 2017 community

# First
Get `sqlite-amalgamation-XXXXXXX.zip` and `sqlite-dll-win32-x86-XXXXXXX.zip` from [here](https://www.sqlite.org/download.html)<br>

![1](https://github.com/pto8913/UE4_memo/blob/images/sqlite_detail_1.png)<br>

# Second
Open Visual Studio, and VScmd from menu tool.<br>
![2](https://github.com/pto8913/UE4_memo/blob/images/sqlite_detail_2.png)<br>

Please enter the following <br>
`"C:\Program Files (x86)\Microsoft Visual Studio 17.0\VC\bin\lib.exe" /DEF:sqlite3.def /MACHINE:x86 /OUT:sqlite3.lib`

# Finally
Add the obtained file to your project.<br>
note: Don't forget to add the include file path and the path to lib.<br>
<br>
# Example code

```C++:sample.cpp
#include<sqlite3.h>
#include<iostream>

int main(){
  sqlite3 *db;
  int ret = sqlite3_open("your database path", &db);
  // Error check
  if (ret) {
    std::cout << "DB open error" << std::endl;
    // close db : It is always necessary
    sqlite3_close(db);
    return -1;
  }
  
  // Execute query
  sqlite3_stmt *stmt = nullptr;
  ret = sqlite3_prepare_v2(db, "your query", -1, &stmt, nullptr);
  // Error check
  if (ret) {
    std::cout << "query error" << std::endl;
    // Release statement : It is always necessary
    sqlite3_finalize(stmt);
    // Close db : It is always necessary
    sqlite3_close(db);
    return -1;
  }
  
  // fetch data
  while (SQLITE_ROW == (ret = sqlite3_step(stmt))){
    // example query : select id, name from table;
    // (stmt, 0) <- you can get id
    // (stmt, 1) <- you can get name
    int value = sqlite3_column_int(stmt, 0) // for example
    std::cout << value << std::endl;
  }
  return 0;
}
```
