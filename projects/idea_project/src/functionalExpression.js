var poly = function (apply) {
    return function () {
        var args = arguments;
        return function (x, y, z) {
            var precalc = [];
            for (var i = 0; i < args.length; i++)
                precalc.push(args[i](x,y,z));
            return apply.apply(null, precalc);
        }
    }
};

var variable = function (name) {
    return function (x, y, z) {
        switch (name) {
            case 'x': {
                return x;
            }
            case 'y': {
                return y;
            }
            case 'z': {
                return z;
            }
        }
    }
};

var x = variable('x');

var y = variable('y');

var z = variable('z');

var cnst = function (value) {
    return function () {
        return value;
    }
};

var pi = cnst(Math.PI);

var e = cnst(Math.E);


var negate = poly(
    function (arg) {
        return -arg;
    }
);

var cube = poly(
    function (arg) {
        return Math.pow(arg, 3);
    }
);

var cuberoot = poly(
    function (arg) {
        return Math.pow(arg, 1.0 / 3);
    }
);

var add = poly(
    function (left, right) {
        return left + right;
    }
);

var subtract = poly(
    function (left, right) {
        return left - right;
    }
);

var multiply = poly(
    function (left, right) {
        return left * right;
    }
);

var divide = poly(
    function (left, right) {
        return left / right;
    }
);


var min3 = poly(
    function () {
        return Math.min.apply(null, arguments);
    }
);

var max5 = poly(
    function () {
        return Math.max.apply(null, arguments);
    }
);