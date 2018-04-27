function Variable (name) {
    this.name = name;
    this.evaluate =  function (x, y, z) {
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
    this.toString = function () {
        return this.name.toString();
    }
};

function Const (value) {
    this.value = value;
    this.evaluate = function (x, y, z) {
        return value;
    }
    this.toString = function () {
        return this.value.toString();
    }
};

function poly (args, apply, type) {
    this.args = args;
    this.apply = apply;
    this.type = type;
    this.args = args;
    this.evaluate = function (x, y, z) {
        for (var i = 0; i < args.length; i++)
            this.args[i] = this.args[i].evaluate(x,y,z);
        return this.apply.apply(null, this.args);
    };
    this.toString = function () {
        if(args.length === 1)
            return this.args[i].toString() + " " + this.type;
        else {
            var res = this.args[0].toString() + " " + this.args[1].toString() + " " + this.type;
            for (var i = 2; i < args.length; i++) {
                res = res + " " + this.args[i].toString() + " " + this.type;
            }
            return res;
        }

    }
};


function Negate (arg) {
    return new poly(arg, function(x) {return -x; }, "negate");
}

function Sqrt(arg) {
    return new poly(arg, function (x) { return Math.sqrt(x);}, "sqrt");
}

function Add (left, right) {
    return new poly(left, right, function(x, y) {return x + y; }, "+");
}

function Subtract (left, right) {
    return new poly(left, right, function(x, y) {return x - y; }, "-");
}

function Multiply (left, right) {
    return new poly(left, right, function(x, y) {return x * y; }, "*");
}

function Divide (left, right) {
    return new poly(left, right, function(x, y) {return x / y; }, "/");
}