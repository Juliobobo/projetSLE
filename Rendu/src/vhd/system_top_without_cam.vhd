-------------------------------------------------------------------------------
-- system_top.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.numeric_std.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library work;
use work.packageVGA.all;


entity system_top is
  Port ( processing_system7_0_MIO : inout std_logic_vector(53 downto 0);
		processing_system7_0_PS_SRSTB : in std_logic;
		processing_system7_0_PS_CLK : in std_logic;
		processing_system7_0_PS_PORB : in std_logic;
		processing_system7_0_DDR_Clk : inout std_logic;
		processing_system7_0_DDR_Clk_n : inout std_logic;
		processing_system7_0_DDR_CKE : inout std_logic;
		processing_system7_0_DDR_CS_n : inout std_logic;
		processing_system7_0_DDR_RAS_n : inout std_logic;
		processing_system7_0_DDR_CAS_n : inout std_logic;
		processing_system7_0_DDR_WEB : out std_logic;
		processing_system7_0_DDR_BankAddr : inout std_logic_vector(2 downto 0);
		processing_system7_0_DDR_Addr : inout std_logic_vector(14 downto 0);
		processing_system7_0_DDR_ODT : inout std_logic;
		processing_system7_0_DDR_DRSTB : inout std_logic;
		processing_system7_0_DDR_DQ : inout std_logic_vector(31 downto 0);
		processing_system7_0_DDR_DM : inout std_logic_vector(3 downto 0);
		processing_system7_0_DDR_DQS : inout std_logic_vector(3 downto 0);
		processing_system7_0_DDR_DQS_n : inout std_logic_vector(3 downto 0);
		processing_system7_0_DDR_VRN : inout std_logic;
		processing_system7_0_DDR_VRP : inout std_logic;
		processing_system7_0_I2C0_SDA : inout std_logic;
		processing_system7_0_I2C0_SCL : inout std_logic;
		led_io : inout std_logic_vector(3 downto 0);
		push_io : in std_logic_vector(3 downto 0);
		switch_io : in std_logic_vector(3 downto 0);
		clk : in std_logic;
		RED : out std_logic_vector(4 downto 0);
  		GREEN : out std_logic_vector(5 downto 0);
  		BLUE : out std_logic_vector(4 downto 0);
		VGA_VS : out std_logic;
		VGA_HS : out std_logic;
		CAMERA_DATA : in std_logic_vector(7 downto 0);
    	--CAMERA_PWREN : out std_logic;
		--CAMERA_RST : out std_logic;
		--CAMERA_SCL : inout std_logic;
		--CAMERA_SDA : inout std_logic;		
		CAMERA_XCLK : out std_logic;
		CAMERA_PCLK : in std_logic;
		CAMERA_HS : in std_logic;
		CAMERA_VS : in std_logic
  );
end system_top;

architecture STRUCTURE of system_top is

component system is
	 Port ( processing_system7_0_MIO : inout std_logic_vector(53 downto 0);
			 processing_system7_0_PS_SRSTB : in std_logic;
			 processing_system7_0_PS_CLK : in std_logic;
			 processing_system7_0_PS_PORB : in std_logic;
			 processing_system7_0_DDR_Clk : inout std_logic;
			 processing_system7_0_DDR_Clk_n : inout std_logic;
			 processing_system7_0_DDR_CKE : inout std_logic;
			 processing_system7_0_DDR_CS_n : inout std_logic;
			 processing_system7_0_DDR_RAS_n : inout std_logic;
			 processing_system7_0_DDR_CAS_n : inout std_logic;
			 processing_system7_0_DDR_WEB : out std_logic;
			 processing_system7_0_DDR_BankAddr : inout std_logic_vector(2 downto 0);
			 processing_system7_0_DDR_Addr : inout std_logic_vector(14 downto 0);
			 processing_system7_0_DDR_ODT : inout std_logic;
			 processing_system7_0_DDR_DRSTB : inout std_logic;
			 processing_system7_0_DDR_DQ : inout std_logic_vector(31 downto 0);
			 processing_system7_0_DDR_DM : inout std_logic_vector(3 downto 0);
			 processing_system7_0_DDR_DQS : inout std_logic_vector(3 downto 0);
			 processing_system7_0_DDR_DQS_n : inout std_logic_vector(3 downto 0);
			 processing_system7_0_DDR_VRN : inout std_logic;
			 processing_system7_0_DDR_VRP : inout std_logic;
			 processing_system7_0_I2C0_SDA : inout std_logic;
			 processing_system7_0_I2C0_SCL : inout std_logic);
end component system;

 attribute BOX_TYPE : STRING;
 attribute BOX_TYPE of system : component is "user_black_box";
 
 signal		CAMERA_DATA_q : std_logic_vector(7 downto 0);
 signal		CAMERA_HS_q :  std_logic;
 signal		CAMERA_VS_q :std_logic;

component clk_pll
	 Port ( CLK_IN1 : in STD_LOGIC;
			CLK_OUT1 : out STD_LOGIC;
			CLK_OUT2 : out STD_LOGIC;
			RESET : in STD_LOGIC;
			LOCKED : out STD_LOGIC);
end component clk_pll;

--component Camera_Data_Simu
--    Port ( pclk : in STD_LOGIC;
--			  href : out STD_LOGIC;
--         vs : out STD_LOGIC;
--         data_out : out STD_LOGIC_VECTOR (7 downto 0));
--end component Camera_Data_Simu;

component VGA_generator
    Port ( clk : in STD_LOGIC;
    		btn3 : in STD_LOGIC;								
			Hsync : out STD_LOGIC;
			Vsync : out STD_LOGIC;
			addr : out STD_LOGIC_VECTOR (16 downto 0);
			coord : out coordonnee;
			activeArea : out boolean;
			reset : out STD_LOGIC);
end component VGA_generator;

component Camera_Capture
    Port ( pclk : in STD_LOGIC;
    	   reset : in STD_LOGIC;
         	href : in STD_LOGIC;
			vs_cam : in STD_LOGIC;
			data_in : in STD_LOGIC_VECTOR (7 downto 0);
			addr : out STD_LOGIC_VECTOR (16 downto 0);
			data_out : out STD_LOGIC_VECTOR (15 downto 0);
			coord : out coordonnee;
			we : out STD_LOGIC_VECTOR(0 DOWNTO 0);
			writting : out STD_LOGIC_VECTOR(0 DOWNTO 0));
end component Camera_Capture;

component mem_lum_opt
	 Port ( clka : in STD_LOGIC;
			wea : in STD_LOGIC_VECTOR(0 DOWNTO 0);
    		addra : in STD_LOGIC_VECTOR(16 DOWNTO 0);
    		dina : in STD_LOGIC_VECTOR(7 DOWNTO 0);
    		clkb : in STD_LOGIC;
   			addrb : in STD_LOGIC_VECTOR(16 DOWNTO 0);
   			doutb : out STD_LOGIC_VECTOR(7 DOWNTO 0));
end component mem_lum_opt;

component multiplexer_RGB is
    Port ( clk : in STD_LOGIC;
    		sw0 : in STD_LOGIC;	
			btn0 : in STD_LOGIC;					
			btn1 : in STD_LOGIC;
			btn2 : in STD_LOGIC;
			coord : in coordonnee;
			data  : in STD_LOGIC_VECTOR (15 downto 0);
			activeArea : in boolean;
			Hsync : in STD_LOGIC;
			Vsync : in STD_LOGIC;
			VGA_hs : out STD_LOGIC;
			VGA_vs : out STD_LOGIC;
			VGA_r : out STD_LOGIC_VECTOR (4 downto 0);
			VGA_g : out STD_LOGIC_VECTOR (5 downto 0);
			VGA_b : out STD_LOGIC_VECTOR (4 downto 0));
end component multiplexer_RGB;

component Main_Comp_Decomp_Tot_Main_Fonction is 
	Port ( 
    start : IN STD_LOGIC;
    done : OUT STD_LOGIC;
    nblevels_rsc_z : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
    nblevels_triosy_lz : OUT STD_LOGIC;
    Src_triosy_lz : OUT STD_LOGIC;
    Comp_triosy_lz : OUT STD_LOGIC;
    Vga_triosy_lz : OUT STD_LOGIC;
    --Main_Comp_Decomp_tot_Main_Fonction_return_triosy_lz : OUT STD_LOGIC;
    clk : IN STD_LOGIC;
    rst : IN STD_LOGIC;
    Src_rsc_singleport_data_in : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);
    Src_rsc_singleport_addr : OUT STD_LOGIC_VECTOR (16 DOWNTO 0);
    Src_rsc_singleport_re : OUT STD_LOGIC;
    Src_rsc_singleport_we : OUT STD_LOGIC;
    Src_rsc_singleport_data_out : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
    Comp_rsc_singleport_data_in : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);
    Comp_rsc_singleport_addr : OUT STD_LOGIC_VECTOR (16 DOWNTO 0);
    Comp_rsc_singleport_re : OUT STD_LOGIC;
    Comp_rsc_singleport_we : OUT STD_LOGIC;
    Comp_rsc_singleport_data_out : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
    Vga_rsc_singleport_data_in : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);
    Vga_rsc_singleport_addr : OUT STD_LOGIC_VECTOR (16 DOWNTO 0);
    Vga_rsc_singleport_re : OUT STD_LOGIC;
    Vga_rsc_singleport_we : OUT STD_LOGIC;
    Vga_rsc_singleport_data_out : IN STD_LOGIC_VECTOR (7 DOWNTO 0)
  );
end component Main_Comp_Decomp_Tot_Main_Fonction;

--Ajout Ram_init
component ram_init is
  PORT (
	clka : IN STD_LOGIC;
	ena : IN STD_LOGIC;  
	wea : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
    	addra : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
    	dina : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    	clkb : IN STD_LOGIC;
    	enb : IN STD_LOGIC;  
  	addrb : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
    	doutb : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
  );
end component ram_init;

signal clk_VGA, pclk_cam : STD_LOGIC; 
signal we : STD_LOGIC_VECTOR(0 DOWNTO 0);
signal address_cam, address_VGA : STD_LOGIC_VECTOR (16 downto 0);
signal data_cam : STD_LOGIC_VECTOR (15 downto 0);
signal data_VGA : STD_LOGIC_VECTOR (15 downto 0);
signal coord_VGA, coord_cam : coordonnee;
signal img_active : boolean;
signal hs, vs : STD_LOGIC; 
signal rst_VGA : STD_LOGIC; 
--signal CAMERA_DATA : STD_LOGIC_VECTOR (7 downto 0);
--signal CAMERA_HS, CAMERA_VS : STD_LOGIC;

-- Signals linked to RAMs
signal addra_1 : STD_LOGIC_VECTOR (16 downto 0);
signal addrb_1, addrb_2, addrb_3 : STD_LOGIC_VECTOR (16 downto 0);
signal dina_1, dina_2, dina_3, doutb_1, doutb_2, doutb_3 : STD_LOGIC_VECTOR (7 downto 0);
signal we_1, we_2, we_3 : STD_LOGIC_VECTOR (0 downto 0);

-- Signals linked to CatapultC module
signal start_signal, done_signal : STD_LOGIC;
signal not_we_1, not_we_2, not_we_3 : STD_LOGIC;
signal dina_1_catC : STD_LOGIC_VECTOR (7 downto 0);
signal addr_1_catC, addr_2_catC, addr_3_catC : STD_LOGIC_VECTOR (16 downto 0);

-- Added for iteration
signal cam_writting : STD_LOGIC_VECTOR(0 downto 0);
--type FSM_with_cam is (WaitingForFrame, ReadingFrame, Treating, Synchronizing);
type FSM_without_cam is (WaitingWC, TreatingWC);
--signal etat_cam_q, etat_cam_d : FSM_with_cam;
signal etat_q, etat_d : FSM_without_cam;

-- Added for control of saturation
signal saturate_sig : STD_LOGIC;

-- Added for control of the level of compression
signal nbLev_sig_q, nbLev_sig_d : STD_LOGIC_VECTOR (3 DOWNTO 0);
signal pushed_q, pushed_d : BOOLEAN;
type FSM_compression is (rst, switch_inc, switch_wait, switch_3);
signal etat_comp_q, etat_comp_d : FSM_compression;

begin

	-- The 'write enable' signals generated by CatapultC work with a reversed logic
	-- compared to Xilinx memories. So we reverse the signals that are sent to the memories.
	we_2(0) <= not not_we_2;

	-- Linking ram3 with the VGA handling module signals
	--data_VGA <= saturate(doutb_3, saturate_sig);

	-- We control whether we saturate the final picture or not with a switch
	saturate_sig <= '1'; --switch_io(3);
	
	-- This process is used to freeze the picture while observing the screen
	freeze: process(switch_io, not_we_3)
	begin
		if switch_io(2) = '1'
		then
			we_3(0) <= not not_we_3;
		else
			we_3 <= "0";
		end if;
	end process;
	
	-- We use some Leds to check the current level of compression right on the zybo card
	print_nbLev: process(nbLev_sig_q)
	begin
		led_io(1) <= nbLev_sig_q(0);
		led_io(2) <= nbLev_sig_q(1);
		led_io(3) <= nbLev_sig_q(2);
	end process;
	
	-- fsm for level of compression
	sync_nbLev: process(clk_VGA)
	begin
		if clk_VGA'event and clk_VGA = '1' then
			if rst_VGA = '1' then
				etat_comp_q <= rst;
				nbLev_sig_q <= "0000";
				
			else
				etat_comp_q <= etat_comp_d;
				nbLev_sig_q <= nbLev_sig_d;		
			end if;
		end if;
	end process;
	
	comb_nbLev: process(etat_comp_q, nbLev_sig_q, switch_io, push_io)	

	begin
		--Default
		nbLev_sig_d <= nbLev_sig_q;
		etat_comp_d <= etat_comp_q;

		case etat_comp_q is
			when rst =>

				nbLev_sig_d <= "0000";

				if push_io(0) = '1' then
					etat_comp_d <= switch_wait;

				end if;

			when switch_wait =>
				if push_io(0) = '0' then
					etat_comp_d <= switch_inc;
					nbLev_sig_d <= nbLev_sig_q;
				end if;

			when switch_inc =>

				nbLev_sig_d <= nbLev_sig_q + 1;
				
				if nbLev_sig_q = 4 then
					etat_comp_d <= rst;
				else 
					etat_comp_d <= switch_3;
		
				end if;
				

			when switch_3 =>
				if push_io(0) = '1' then
					etat_comp_d <= switch_wait;
				end if;
		end case;	
	end process;

	-- We use the buttons of the zybo card to change the level of compression
	--sync_nbLev: process(switch_io, push_io, rst_VGA, pushed)
	--begin
	--	if rst_VGA = '1' then
	--		nbLev_sig <= "000";
	--		pushed <= false;
	--	elsif switch_io(1) = '0' then
	--		nbLev_sig <= "001";
	--		pushed <= false;
	--	elsif push_io(0) = '1' and pushed = false then
	--		nbLev_sig <= nbLev_sig + 1;
	--		pushed <= true;
	--	elsif push_io(0) = '1' and pushed = true then
	--		nbLev_sig <= nbLev_sig;
	--		pushed <= true;
	--	elsif push_io(0) = '0' then
	--		nbLev_sig <= nbLev_sig;
	--		pushed <= false;
	--	end if;
	--end process;


	sync_fsm: process(clk_VGA)
	begin
		if clk_VGA'event and clk_VGA = '1' then
			if rst_VGA = '1' then
				etat_q <= WaitingWC;
			else
				etat_q <= etat_d;
			end if;
		end if;
	end process;

	fsm: process(etat_q, done_signal, dina_1_catC, not_we_1, addr_1_catC)
	
	begin
		etat_d <= etat_q;
		dina_1 <= dina_1_catC;
		we_1(0) <= not not_we_1;
		addra_1 <= addr_1_catC;
			
		case etat_q is
			when WaitingWC =>
				start_signal <= '0';
				if done_signal = '0' then
					etat_d <= TreatingWC;
				end if; 

			when TreatingWC =>
				start_signal <= '1';
				if done_signal = '1' then
					etat_d <= WaitingWC;
				end if;
		end case;
	end process;

--		sync_fsm: process(clk_VGA)
--		begin
--			if clk_VGA'event and clk_VGA = '1' then
--				if rst_VGA = '1' then
--					etat_cam_q <= WaitingForFrame;
--				else
--					etat_cam_q <= etat_cam_d;
--				end if;
--			end if;
--		end process;

		-- This fsm is used to coordinate the entries plugged on the ram1 and the
		-- launch/stop of the CatapultC "Main_tran_ond_Opt" module.
--		fsm: process(etat_cam_q, done_signal, cam_writting, dina_1_catC, data_cam, 
--							we, not_we_1, addr_1_catC, address_cam)
--		begin
	
--			etat_cam_d <= etat_cam_q;

--			case etat_cam_q is
--				when WaitingForFrame => -- Attente d'une nouvelle image à traiter.
--					start_signal <= '0';
--					dina_1 <= dina_1_catC;
--					we_1(0) <= not not_we_1;
--					addra_1 <= addr_1_catC;
--
--					if cam_writting = "1" then	
--						etat_cam_d <= ReadingFrame;
--					end if;

--				when ReadingFrame => -- Ecriture d'une nouvelle image à traiter dans ram1.
--					start_signal <= '0';
					--dina_1 <= rgb2lum(data_cam);
--					dina_1 <= (( "000" & data_cam(15 downto 11)) +
--							data_cam(10 downto 5) +
--							data_cam(4 downto 0));
--					we_1 <= we;
--					addra_1 <= address_cam;

--					if cam_writting = "0" then
--						etat_cam_d <= Treating;
--					end if;
			
--				when Treating => -- La transformée en ondelettes est en cours.
						 -- Le traitement se passe entre ram1 et ram2.
						 -- Le résultat final est écrit dans ram3.
--					start_signal <= '1';
--					dina_1 <= dina_1_catC;
--					we_1(0) <= not not_we_1;
--					addra_1 <= addr_1_catC;

--					if done_signal = '1' then
--						etat_cam_d <= Synchronizing;
--					end if;

--				when Synchronizing => -- Au cas où Camera_Capture est en train d'écrire une image,
						      -- on attend qu'il termine.
--					start_signal <= '0';
--					dina_1 <= dina_1_catC;
--					we_1(0) <= not not_we_1;
--					addra_1 <= addr_1_catC;

--					if cam_writting = "0" then
--						etat_cam_d <= WaitingForFrame;
--					end if;

--			end case;
--		end process;


		-- Changement de connexion Ram
		change_VGA: process(switch_io, address_VGA, addr_1_catC, addr_2_catC, doutb_1, doutb_2, doutb_3, saturate_sig)

		begin
			--Ram 1 connected to VGA
			if (switch_io(1) = '1') then
				addrb_1 <= address_VGA;
				--addrb_2 <= addr_2_catC;
				addrb_3 <= "00000000000000000";
				data_VGA <= saturate(doutb_1, saturate_sig);
			--Ram 2 connected to VGA	
			--elsif(switch_io(1) = '0' and switch_io(3) = '1') then
				--addrb_1 <= addr_1_catC;
				--addrb_2 <= address_VGA;
				--addrb_3 <= "00000000000000000";
				--data_VGA <= saturate(doutb_2, saturate_sig);
			--Ram 3 connected to VGA
			else
				addrb_1 <= addr_1_catC;
				--addrb_2 <= addr_2_catC;
				addrb_3 <= address_VGA;
				data_VGA <= saturate(doutb_3, saturate_sig);	
			end if;
		end process;		
		
system_i: system
	 Port map ( processing_system7_0_MIO => processing_system7_0_MIO,
			 processing_system7_0_PS_SRSTB => processing_system7_0_PS_SRSTB,
			 processing_system7_0_PS_CLK => processing_system7_0_PS_CLK,
			 processing_system7_0_PS_PORB => processing_system7_0_PS_PORB,
			 processing_system7_0_DDR_Clk => processing_system7_0_DDR_Clk,
			 processing_system7_0_DDR_Clk_n => processing_system7_0_DDR_Clk_n,
			 processing_system7_0_DDR_CKE => processing_system7_0_DDR_CKE,
			 processing_system7_0_DDR_CS_n => processing_system7_0_DDR_CS_n,
			 processing_system7_0_DDR_RAS_n => processing_system7_0_DDR_RAS_n,
			 processing_system7_0_DDR_CAS_n => processing_system7_0_DDR_CAS_n,
			 processing_system7_0_DDR_WEB => processing_system7_0_DDR_WEB,
			 processing_system7_0_DDR_BankAddr => processing_system7_0_DDR_BankAddr,
			 processing_system7_0_DDR_Addr => processing_system7_0_DDR_Addr,
			 processing_system7_0_DDR_ODT => processing_system7_0_DDR_ODT,
			 processing_system7_0_DDR_DRSTB => processing_system7_0_DDR_DRSTB,
			 processing_system7_0_DDR_DQ => processing_system7_0_DDR_DQ,
			 processing_system7_0_DDR_DM => processing_system7_0_DDR_DM,
			 processing_system7_0_DDR_DQS => processing_system7_0_DDR_DQS,
			 processing_system7_0_DDR_DQS_n => processing_system7_0_DDR_DQS_n,
			 processing_system7_0_DDR_VRN => processing_system7_0_DDR_VRN,
			 processing_system7_0_DDR_VRP => processing_system7_0_DDR_VRP,
			 processing_system7_0_I2C0_SDA => processing_system7_0_I2C0_SDA,
			 processing_system7_0_I2C0_SCL => processing_system7_0_I2C0_SCL
			 );

pll: clk_pll
	 Port map ( CLK_IN1 => clk,	 -- 125 MHz
			CLK_OUT1 => clk_VGA,		 -- 24 MHz
			CLK_OUT2 => CAMERA_XCLK, -- 24 MHz
			RESET => push_io(3),
			LOCKED => led_io(0)
			);

--led_io(1) <= '0';
--led_io(2) <= '0';
--led_io(3) <= '1';
		
--cam_clk_buf : IBUFG
--	Port map
--   (O => pclk_cam,
--    I => CAMERA_PCLK);
    
--cam_simu: Camera_Data_Simu
--    Port map ( pclk => pclk_cam,
--			    href => CAMERA_HS,
--           vs => CAMERA_VS,
--           data_out => CAMERA_DATA
--			    );

vga: VGA_generator
    Port map ( clk => clk_VGA,
	  	btn3 => push_io(3),
           	Hsync => hs,
           	Vsync => vs,
	  	addr => address_VGA,
	  	coord => coord_VGA,
	  	activeArea => img_active,
	  	reset => rst_VGA
			  );
 
sync_cam : process(CAMERA_PCLK)
begin
  if rising_edge(CAMERA_PCLK) then
		CAMERA_DATA_q  <= CAMERA_DATA ;
		CAMERA_HS_q <= CAMERA_HS;
		CAMERA_VS_q <= CAMERA_VS;
  end if;
end process sync_cam;

capture: Camera_Capture
    Port map ( pclk => CAMERA_PCLK,
    		  reset => rst_VGA,
           href => CAMERA_HS_q,
           vs_cam => CAMERA_VS_q,
           data_in => CAMERA_DATA_q,
           addr => address_cam,
           data_out => data_cam,
           coord => coord_cam,
           we => we,
	   writting => cam_writting
			  );
ram1: ram_init
	Port map ( clka => CAMERA_PCLK,
	  			ena => '1', 
		  		wea => we_1,
  		  		addra => addra_1,
    		  	dina => dina_1,
    		  	clkb => clk_VGA,
          		enb => '1',
   		  		addrb => addrb_1, --addr_1_catC,
   		  		doutb => doutb_1
	);

--Image a traiter est dans ram1			  
--ram1: mem_lum_opt
--	 Port map ( clka => CAMERA_PCLK, 
--		  wea => we_1,
 -- 		  addra => addra_1,
--		  dina => dina_1,
--		  clkb => clk_VGA,
 --  		  addrb => addrb_1, --addr_1_catC,
  -- 		  doutb => doutb_1
   --		  );
			  
ram2: mem_lum_opt
	 Port map ( clka => clk_VGA, 
		  		wea => we_2,
    		  	addra => addr_2_catC,
    		  	dina => dina_2,
    		  	clkb => clk_VGA,
   		  		addrb => addr_2_catC, --addrb_2, 
   		  		doutb => doutb_2
   		  );
			  
ram3: mem_lum_opt
	 Port map ( clka => clk_VGA, 
	  			wea => we_3,
   		  		addra => addr_3_catC,
    		  	dina => dina_3,
    		  	clkb => clk_VGA,
   		  		addrb => addrb_3,
   		  		doutb => doutb_3
   		  );

mux: multiplexer_RGB
	Port map ( clk => clk_VGA,
    		  sw0 => switch_io(0),
    		  btn0 => push_io(0),
			  btn1 => push_io(1),	
			  btn2 => push_io(2),
			  coord => coord_VGA,
			  data => data_VGA,
			  activeArea => img_active,
			  Hsync => hs,
			  Vsync => vs,
			  VGA_hs => VGA_HS,
			  VGA_vs => VGA_VS,
			  VGA_r => RED,
			  VGA_g => GREEN,
			  VGA_b => BLUE
			  );

comp_decomp_tot : Main_Comp_Decomp_Tot_Main_Fonction
	Port map ( 
		start => start_signal,
		done => done_signal,
		nblevels_rsc_z => nbLev_sig_q,
		nblevels_triosy_lz => open,
		Src_triosy_lz => open,
		Vga_triosy_lz => open,
		Comp_triosy_lz => open,
		--Main_Comp_Decomp_tot_Main_Fonction_return_triosy_lz => open,
		clk => clk_VGA, --CAMERA_PCLK,  --clk_VGA,
		rst => rst_VGA,
		Src_rsc_singleport_data_in => dina_1_catC,
		Src_rsc_singleport_addr => addr_1_catC,
		Src_rsc_singleport_re => open,
		Src_rsc_singleport_we => not_we_1,
		Src_rsc_singleport_data_out => doutb_1,
		Comp_rsc_singleport_data_in => dina_2,
		Comp_rsc_singleport_addr => addr_2_catC,
		Comp_rsc_singleport_re => open,
		Comp_rsc_singleport_we => not_we_2,
		Comp_rsc_singleport_data_out => doutb_2,
		Vga_rsc_singleport_data_in => dina_3,
		Vga_rsc_singleport_addr => addr_3_catC,
		Vga_rsc_singleport_re => open,
		Vga_rsc_singleport_we => not_we_3,
		Vga_rsc_singleport_data_out => doutb_3
		);


end architecture STRUCTURE;

