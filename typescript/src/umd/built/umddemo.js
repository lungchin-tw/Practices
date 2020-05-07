(function (root, factory) {
    if (typeof define === 'function' && define.amd) {
        define([], function () {
            return factory.call(root);
        });
    }
    else {
        root.umddemo = factory.call(root);
    }
}(this, function () {
    'use strict';
    function test() {
        console.log("umddemo.test");
    }
    return {
        test: test,
    };
}));
//# sourceMappingURL=umddemo.js.map