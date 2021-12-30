// Try: tsc ./callback/callback.ts --outDir ./build/callback

function testNeverType(): never {
    throw new Error("testNeverType");
}

testNeverType();