class Bodyb
  def initialize(b,t,d,c)
    @bi=b.to_i
    @tr=t.to_i
    @de=d.to_i
    @c="bodyb No.#{c}"

  end
  def pump(mus)
    case mus
    when 'tr'
      @tr+=1
    when 'bi'
      @bi+=1
    when 'de'
      @de+=1
    end
    puts "#{@c}"
    puts" bic=#{@bi}\ntr=#{@tr}\ndelt=#{@de}\n "
  end
end