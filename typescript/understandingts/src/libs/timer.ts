
export class StopWatch {
    begin: number

    constructor() {
        this.begin = new Date().getTime();
    }

    start() {
        this.begin = new Date().getTime();
    }

    elapsed(): number {
        return new Date().getTime() - this.begin
    }
}