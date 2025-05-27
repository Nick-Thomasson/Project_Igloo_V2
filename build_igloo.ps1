& "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cl /std:c++17 /EHsc /I "C:\VS\vcpkg\installed\x64-windows\include" *.cpp /link /LIBPATH:"C:\VS\vcpkg\installed\x64-windows\lib" pqxx.lib libpq.lib wxmsw32u_core.lib wxbase32u.lib comctl32.lib rpcrt4.lib
