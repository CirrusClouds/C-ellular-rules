with Ada.Text_IO;    

    -- I constructed the emacs-major-mode w/ which I wrote the code too!
    
    procedure Game_of_Life is
    use Ada.Text_IO;
    
    Height : constant Positive := 40;
    Width : constant Positive := 100;
        
    type Cell is (Dead, Alive);
    type Rows is mod Height;
    type Cols is mod Width;
    type Board is array (Rows, Cols) of Cell;
    type Neighbours is range 0 .. 8;
    type counter is range 0 .. 750;
        
    procedure Render_Board(B: Board) is
    begin
          for Row in Rows loop
            for Col in Cols loop
                case B(Row, Col) is
                    when Alive => Put('#');
                    when Dead => Put('.');
                end case;
            end loop;
            New_Line;
        end loop;
    end;

    function Count_Neighbours(B: Board; i: Rows; j: Cols) return Neighbours is
        Result : Neighbours := 0;
    begin
        for Subrow in Rows range (i-1) .. (i+1) loop
            for Subcol in Cols range (j-1) .. (j+1) loop
                Result := Result + (if ((Subcol /= j) or (Subrow /= i)) and (B(Subrow, Subcol) = Alive) then 1 else 0);
            end loop;
        end loop;
        return Result;
    end;
        

    function Next(B: Board) return Board is
        Result : Board;
    begin
        for Row in Rows loop
            for Col in Cols loop
                declare
                Neighbour_Score : Neighbours := Count_Neighbours(B, Row, Col);
                begin
                    case B(Row, Col) is
                        when Dead =>
                            Result(Row, Col) := (if Neighbour_Score = 3 then Alive else Dead);
                        when Alive =>
                            Result(Row, Col) := (if Neighbour_Score in 2..3 then Alive else Dead);
                    end case;
                end;
            end loop;
        end loop;
    
        return Result;
    end;

    Current : Board := (
        (others => Dead),
        ( Alive, Alive, Dead, others => Dead),
        ( Dead, Dead, Alive, others => Dead),
        ( Alive, Alive, Alive, others => Dead),
        (others => Dead),
        (others => Dead),
        ( Alive, Alive, Alive, Dead, Dead, Dead, Alive, Alive, Alive, Alive, Dead, others=>Dead),
        (others => Dead),
        (others => Alive),
        others => (others => Dead)
    );                         

begin
    for i in counter loop
        Put("Round");
        Put(i'Image);
        New_Line;
        Render_Board(Current);
        Current := Next(Current);
        New_Line;
    end loop;
end;
