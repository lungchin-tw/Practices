'use strict'; // -> This directive let this script work in modern mode

var Role;
(function (Role){
    Role[Role['ADMIN'] = 0] = 'ADMIN'
    Role[Role['AUTHOR'] = 1] = 'AUTHOR'
})(Role || (Role = {}));

console.log(Role)