<html>
    <head>
        <title>Upload file</title>
    </head>
    <body>
        <form enctype="multipart/form-data" action="upload" method="post">
            <input type="file" name="uploadfile" />
            <input type="hidden" name="token" value="{{.}}"/>
            </br></br>
            <input type="submit" value="upload" />
        </form>
    </body>
</html>