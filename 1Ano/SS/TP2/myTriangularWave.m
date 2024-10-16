function [x, t] = myTriangularWave(d, N, f, Fs)
    if nargin < 5
        Fs = 8e3;
    end

    if rem(N, 2) == 0
      N--
    endif

    ts = 1 / Fs;

    t = 0:ts:4 * 1/f;

    fase = 0;
    CK = 0;
    x = 0;

    for k = -N:2:N
        ck = (2 / (pi * k)) .^ 2;

        s = abs(ck)*cos(2*pi*k*f*t+fase);

        x = x + s;
        CK = [CK ck];
    end
end
