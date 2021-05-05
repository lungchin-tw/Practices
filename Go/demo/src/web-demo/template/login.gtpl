<html>
    <head>
    <title></title>
    </head>
    <body>
        <form action="/login" method="post">
            Username:<input type="text" name="username"></br>
            Password:<input type="password" name="password"></br>
            <div>
                Fruite:<select name="fruit">
                    <option value="apple">apple</option>
                    <option value="pear">pear</option>
                    <option value="banana">banana</option>
                </select>
            </div>
            <div>
                <h3>Gender</h3>
                <input type="radio" name="gender" value="1">Male
                <input type="radio" name="gender" value="2">Female
            </div>
            <div>
                <h3>Habits</h3>
                <input type="checkbox" name="interest" value="football">Football
                <input type="checkbox" name="interest" value="bedminton">Bedminton
            </div>
            </br>
            <input type="hidden" name="token" value="{{.}}">
            <input type="submit" value="Login">
        </form>
    </body>
</html>