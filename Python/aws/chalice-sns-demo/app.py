from chalice import Chalice

app = Chalice(app_name='jacky-chen-chalice-sns-demo', debug=True)


@app.on_sns_message(topic='Jacky-Chen-Demo')
def handle_sns_message(event):
    app.log.debug(
        "SNS: {Subject: \"%s\", Message:\"%s\"}",
        event.subject,
        event.message,
    )