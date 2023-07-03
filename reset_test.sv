//-------------------------------------------------------------------------
//						www.verificationguide.com
//-------------------------------------------------------------------------
`include "environment.sv"
program test(mem_intf intf);
  
  class my_trans extends transaction;
    
    bit [1:0] count;
    
    function void pre_randomize();
      wr_en.rand_mode(0);
      rd_en.rand_mode(0);
      addr.rand_mode(0);
      
       wait(!intf.reset); begin
       $display("--------- Write operation started Started ---------");
            
        wr_en = 1;
        rd_en = 0;
        addr  = cnt;      
	wait(intf.reset);
        wr_en = 0;
        rd_en = 1;
        addr  = cnt;     
      end
      cnt++;
    endfunction
    
  endclass
    
  //declaring environment instance
  environment env;
  my_trans my_tr;
  
  initial begin
    //creating environment
    env = new(intf);
    
    my_tr = new();
    
    //setting the repeat count of generator as 4, means to generate 4 packets
    env.gen.repeat_count = 10;
    
    env.gen.trans = my_tr;
    
    //calling run of env, it interns calls generator and driver main tasks.
    env.run();
  end
endprogram
