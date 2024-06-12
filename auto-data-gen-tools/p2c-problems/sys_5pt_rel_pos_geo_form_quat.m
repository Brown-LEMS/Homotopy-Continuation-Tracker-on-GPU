function [f, numOfVars, num_of_params] = sys_5pt_rel_pos_geo_form_quat()
    
    %> define systems
    %> variables
    syms x1 x2 x3 x4 x5 x6
    %> parameters
    syms p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 p15 p16 p17 p18 p19 p20
    
    numOfVars = 6;
    num_of_params = 20;
    
    %> Version 2
    f(1) = p2*p3 - p1*p4 + p1*x2 - p2*x1 - p3*x2 + p4*x1 - 2*p2*p3*x3^2 + 2*p1*p4*x4^2 + 2*p1*p4*x5^2 - 2*p2*p3*x5^2 + 2*p2*x1*x3^2 - 2*p1*x2*x4^2 - 2*p1*x2*x5^2 + 2*p2*x1*x5^2 + 2*p3*x2*x3^2 - 2*p4*x1*x3^2 + 2*p3*x2*x4^2 - 2*p4*x1*x4^2 - 2*p3*x3*x6 + 2*p3*x4*x5 - 2*p4*x3*x5 - 2*p4*x4*x6 + 2*x1*x3*x6 - 2*x1*x4*x5 + 2*x2*x3*x5 + 2*x2*x4*x6 + 2*p1*p3*x3*x4 - 2*p2*p4*x3*x4 + 2*p1*p3*x5*x6 + 2*p2*p4*x5*x6 - 2*p1*x1*x3*x4 + 2*p2*x2*x3*x4 - 2*p1*x1*x5*x6 - 2*p2*x2*x5*x6 - 2*p1*p3*x2*x3*x5 + 2*p1*p4*x1*x3*x5 + 2*p1*p3*x2*x4*x6 - 2*p1*p4*x1*x4*x6 - 2*p2*p3*x2*x3*x6 - 2*p2*p3*x2*x4*x5 + 2*p2*p4*x1*x3*x6 + 2*p2*p4*x1*x4*x5;
    f(2) = p6*p7 - p5*p8 + p5*x2 - p6*x1 - p7*x2 + p8*x1 - 2*p6*p7*x3^2 + 2*p5*p8*x4^2 + 2*p5*p8*x5^2 - 2*p6*p7*x5^2 + 2*p6*x1*x3^2 - 2*p5*x2*x4^2 - 2*p5*x2*x5^2 + 2*p6*x1*x5^2 + 2*p7*x2*x3^2 - 2*p8*x1*x3^2 + 2*p7*x2*x4^2 - 2*p8*x1*x4^2 - 2*p7*x3*x6 + 2*p7*x4*x5 - 2*p8*x3*x5 - 2*p8*x4*x6 + 2*x1*x3*x6 - 2*x1*x4*x5 + 2*x2*x3*x5 + 2*x2*x4*x6 + 2*p5*p7*x3*x4 - 2*p6*p8*x3*x4 + 2*p5*p7*x5*x6 + 2*p6*p8*x5*x6 - 2*p5*x1*x3*x4 + 2*p6*x2*x3*x4 - 2*p5*x1*x5*x6 - 2*p6*x2*x5*x6 - 2*p5*p7*x2*x3*x5 + 2*p5*p8*x1*x3*x5 + 2*p5*p7*x2*x4*x6 - 2*p5*p8*x1*x4*x6 - 2*p6*p7*x2*x3*x6 - 2*p6*p7*x2*x4*x5 + 2*p6*p8*x1*x3*x6 + 2*p6*p8*x1*x4*x5;
    f(3) = p10*p11 - p9*p12 + p9*x2 - p10*x1 - p11*x2 + p12*x1 - 2*p10*p11*x3^2 + 2*p9*p12*x4^2 + 2*p9*p12*x5^2 - 2*p10*p11*x5^2 + 2*p10*x1*x3^2 - 2*p9*x2*x4^2 - 2*p9*x2*x5^2 + 2*p10*x1*x5^2 + 2*p11*x2*x3^2 - 2*p12*x1*x3^2 + 2*p11*x2*x4^2 - 2*p12*x1*x4^2 - 2*p11*x3*x6 + 2*p11*x4*x5 - 2*p12*x3*x5 - 2*p12*x4*x6 + 2*x1*x3*x6 - 2*x1*x4*x5 + 2*x2*x3*x5 + 2*x2*x4*x6 + 2*p9*p11*x3*x4 - 2*p10*p12*x3*x4 + 2*p9*p11*x5*x6 + 2*p10*p12*x5*x6 - 2*p9*x1*x3*x4 + 2*p10*x2*x3*x4 - 2*p9*x1*x5*x6 - 2*p10*x2*x5*x6 - 2*p9*p11*x2*x3*x5 + 2*p9*p12*x1*x3*x5 + 2*p9*p11*x2*x4*x6 - 2*p9*p12*x1*x4*x6 - 2*p10*p11*x2*x3*x6 - 2*p10*p11*x2*x4*x5 + 2*p10*p12*x1*x3*x6 + 2*p10*p12*x1*x4*x5;
    f(4) = p14*p15 - p13*p16 + p13*x2 - p14*x1 - p15*x2 + p16*x1 - 2*p14*p15*x3^2 + 2*p13*p16*x4^2 + 2*p13*p16*x5^2 - 2*p14*p15*x5^2 + 2*p14*x1*x3^2 - 2*p13*x2*x4^2 - 2*p13*x2*x5^2 + 2*p14*x1*x5^2 + 2*p15*x2*x3^2 - 2*p16*x1*x3^2 + 2*p15*x2*x4^2 - 2*p16*x1*x4^2 - 2*p15*x3*x6 + 2*p15*x4*x5 - 2*p16*x3*x5 - 2*p16*x4*x6 + 2*x1*x3*x6 - 2*x1*x4*x5 + 2*x2*x3*x5 + 2*x2*x4*x6 + 2*p13*p15*x3*x4 - 2*p14*p16*x3*x4 + 2*p13*p15*x5*x6 + 2*p14*p16*x5*x6 - 2*p13*x1*x3*x4 + 2*p14*x2*x3*x4 - 2*p13*x1*x5*x6 - 2*p14*x2*x5*x6 - 2*p13*p15*x2*x3*x5 + 2*p13*p16*x1*x3*x5 + 2*p13*p15*x2*x4*x6 - 2*p13*p16*x1*x4*x6 - 2*p14*p15*x2*x3*x6 - 2*p14*p15*x2*x4*x5 + 2*p14*p16*x1*x3*x6 + 2*p14*p16*x1*x4*x5;
    f(5) = p18*p19 - p17*p20 + p17*x2 - p18*x1 - p19*x2 + p20*x1 - 2*p18*p19*x3^2 + 2*p17*p20*x4^2 + 2*p17*p20*x5^2 - 2*p18*p19*x5^2 + 2*p18*x1*x3^2 - 2*p17*x2*x4^2 - 2*p17*x2*x5^2 + 2*p18*x1*x5^2 + 2*p19*x2*x3^2 - 2*p20*x1*x3^2 + 2*p19*x2*x4^2 - 2*p20*x1*x4^2 - 2*p19*x3*x6 + 2*p19*x4*x5 - 2*p20*x3*x5 - 2*p20*x4*x6 + 2*x1*x3*x6 - 2*x1*x4*x5 + 2*x2*x3*x5 + 2*x2*x4*x6 + 2*p17*p19*x3*x4 - 2*p18*p20*x3*x4 + 2*p17*p19*x5*x6 + 2*p18*p20*x5*x6 - 2*p17*x1*x3*x4 + 2*p18*x2*x3*x4 - 2*p17*x1*x5*x6 - 2*p18*x2*x5*x6 - 2*p17*p19*x2*x3*x5 + 2*p17*p20*x1*x3*x5 + 2*p17*p19*x2*x4*x6 - 2*p17*p20*x1*x4*x6 - 2*p18*p19*x2*x3*x6 - 2*p18*p19*x2*x4*x5 + 2*p18*p20*x1*x3*x6 + 2*p18*p20*x1*x4*x5;
    f(6) = x6^2 + x3^2 + x4^2 + x5^2 - 1;

end
