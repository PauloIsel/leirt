function [x, t] = mySquareWave(A, d, N, f, Fs)
    if nargin < 5
        Fs = 8e3;
    end

    ts = 1 / Fs;

    t = 0:ts:4 * 1/f;

    CK = 0;
    x = 0;

    for k = -N:N
        if k == 0
            ck = A*d;
        else
            ck = (A*d*sinc(k*d));
        end


        if ck < 0 && k < 0
            fase = pi;
        end

        if ck < 0 && k > 0
            fase = -pi;
        end

        if ck >= 0
            fase = 0;
        end

        s = abs(ck)*cos(2*pi*k*f*t+fase);
        x = x + s;
        CK = [CK ck];
    end
end
