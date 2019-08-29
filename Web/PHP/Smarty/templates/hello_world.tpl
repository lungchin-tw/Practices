<!DOCTYPE html>
<html>
    <head>
        <title>{$title}</title>
    </head>
    <body>
        <p><h1>{$message}</h1></p>
        <p><h2>Smarty Builtin Functions</h2></p>
            <p>The current date and time: {$smarty.now|date_format:"%Y-%m-%d %H:%M:%S"}</p>
            <p>$SCRIPT_NAME: {$SCRIPT_NAME}</p>
            <p>SERVER_NAME: {$smarty.server.SERVER_NAME}</p>

        HAY HAY HAY
    </body>
</html>