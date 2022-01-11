// Try: tsc ./src/time-utils/time-utils.ts --outDir ./build/time-utils

import  * as DomUtils from '../libs/domutils.js';

function testTimeUtils(): void {
    const APP = "app"

    // Unit: Millisecond
    DomUtils.AppendChildParagraph(APP, `Date().getTime(): ${new Date().getTime()}`);
    DomUtils.AppendChildParagraph(APP, `Date().valudOf(): ${new Date().valueOf()}`);
}

testTimeUtils();