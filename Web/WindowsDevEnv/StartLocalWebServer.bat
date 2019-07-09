ECHO ON

START "" "C:\php-7.3.3-Win32-VC15-x64\php-cgi.exe" -b 127.0.0.1:9995
START "" "C:\php-7.3.3-Win32-VC15-x64\php-cgi.exe" -b 127.0.0.1:9996
START "" "C:\php-7.3.3-Win32-VC15-x64\php-cgi.exe" -b 127.0.0.1:9997
START "" "C:\php-7.3.3-Win32-VC15-x64\php-cgi.exe" -b 127.0.0.1:9998
START "" "C:\php-7.3.3-Win32-VC15-x64\php-cgi.exe" -b 127.0.0.1:9999
CD /D "C:\nginx-1.17.0"
START nginx
tasklist /fi "imagename eq nginx.exe"
tasklist /fi "imagename eq php-cgi.exe"