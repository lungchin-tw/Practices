class DemoLibBase {
    constructor(msg) {
        this.message = msg;
    }
}
class DemoLibOne extends DemoLibBase {
    constructor(msg) {
        super(msg);
    }
    saySomething() {
        console.log(this.message);
    }
}
//# sourceMappingURL=libdemo.js.map