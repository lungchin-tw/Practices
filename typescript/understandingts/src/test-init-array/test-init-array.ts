// Try: tsc ./src/test-init-array/test-init-array.ts --outDir ./build/test-init-array

import { StopWatch } from '../libs/timer.js';
import  * as DomUtils from '../libs/domutils.js';

function testInitArray(): void {
    const APP = "app"
    const NUM = 1000000
    let stopwatch: StopWatch = new StopWatch();

    // #A1
    stopwatch.start();
    let a1:number[] = new Array(NUM)
    for (let index = 0; index < a1.length; index++) {
        a1[index] = index;
    }

    DomUtils.AppendChildParagraph(APP, `A1(${a1.length}) Elapsed: ${stopwatch.elapsed()}`);

    // #A2
    stopwatch.start();
    let a2:number[] = new Array()
    for (let index = 0; index < NUM; index++) {
        a2.push(index);
    }

    DomUtils.AppendChildParagraph(APP, `A2(${a2.length}) Elapsed: ${stopwatch.elapsed()}`);
}

testInitArray();