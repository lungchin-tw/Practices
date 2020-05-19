cc.Class({
    extends: cc.Component,

    properties: {
        labelStatus: cc.Label,
        webview: cc.WebView,
    },

    onWebFinishLoad: function (sender, event) {
        var loadStatus = "";
        if (event === cc.WebView.EventType.LOADED) {
            loadStatus = " is loaded!";
        } else if (event === cc.WebView.EventType.LOADING) {
            loadStatus = " is loading!";
        } else if (event === cc.WebView.EventType.ERROR) {
            loadStatus = ' load error!';
        }
        console.log(this.webview.url + loadStatus);
        // this.labelStatus.string = this.webview.url + loadStatus;
    },
});
