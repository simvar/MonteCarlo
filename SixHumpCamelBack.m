function f= SixHumpCamelBack(x)
%#codegen
            f= (4-2.1*x(1)*x(1)+x(1)*x(1)*x(1)*x(1)/3)*x(1)*x(1) + x(1)*x(2)+(-4+4*x(2)*x(2))*x(2)*x(2);
end
