cc.Class({
    extends: cc.Component,

    properties: {
        webview: cc.WebView,
    },

    onGoogleSignInClick() {
        console.log("onGoogleSignInClick");
        // this.webview.url = "http://localhost:5500/google/google-sign-in-web-backend/google-sign-in-web-backend.html"
        this.webview.url = "https://lungchin-tw.github.io/authenticationdemo/google/google-sign-in-web-backend/google-sign-in-web-backend.html"
    },
});
