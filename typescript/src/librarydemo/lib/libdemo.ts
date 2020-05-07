
class DemoLibBase {
    readonly message:string;

    constructor(msg: string) {
        this.message = msg;
    }
}

class DemoLibOne extends DemoLibBase {
    constructor(msg: string) {
        super(msg);
    }

    saySomething() {
        console.log(this.message);
    }
}