<div class="row">
  <div class="col-lg-12">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-clock-o fa-fw"></i> 区块概述
      </div>
      <div class="panel-body no-padding">
        <div class="table-responsive">
          <table class="table table-striped table-bordered table-hover">
            <thead>
              <tr>
                <th></th>
                <th class="text-right">预计总区块</th>
                <th class="text-right">已发现</th>
                <th class="text-right">有效</th>
                <th class="text-right">无效</th>
                <th class="text-right">平均难度</th>
                <th class="text-right">预计股份</th>
                <th class="text-right">实际股份</th>
                <th class="text-right">百分比</th>
                <th class="text-right">总数量</th>
                <th class="text-right">预计比例</th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <th>所有时间</th>
                <td class="text-right">{($FIRSTBLOCKFOUND / $COINGENTIME)|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.Total|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.TotalValid|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.TotalOrphan|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.TotalValid > 0}
                  {($LASTBLOCKSBYTIME.TotalDifficulty / $LASTBLOCKSBYTIME.TotalValid)|number_format:"4"}
                {else}
                  0
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.TotalEstimatedShares|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.TotalShares|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.TotalEstimatedShares > 0}
                  <font color="{if (($LASTBLOCKSBYTIME.TotalShares / $LASTBLOCKSBYTIME.TotalEstimatedShares * 100) <= 100)}green{else}red{/if}">{($LASTBLOCKSBYTIME.TotalShares / $LASTBLOCKSBYTIME.TotalEstimatedShares * 100)|number_format:"2"}%</font></b>
                {else}
                  0.00%
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.TotalAmount|number_format:"2"}</td>
                <td class="text-right">{($LASTBLOCKSBYTIME.Total|default:"0.00" / ($FIRSTBLOCKFOUND / $COINGENTIME)  * 100)|number_format:"2"}%</td>
              </tr>
              <tr>
                <th>最近1小时</th>
                <td class="text-right">{(3600 / $COINGENTIME)|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.1HourTotal|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.1HourValid|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.1HourOrphan|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.1HourValid > 0}
                  {($LASTBLOCKSBYTIME.1HourDifficulty / $LASTBLOCKSBYTIME.1HourValid)|number_format:"4"}
                {else}
                  0
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.1HourEstimatedShares|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.1HourShares|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.1HourEstimatedShares > 0}
                  <font color="{if (($LASTBLOCKSBYTIME.1HourShares / $LASTBLOCKSBYTIME.1HourEstimatedShares * 100) <= 100)}green{else}red{/if}">{($LASTBLOCKSBYTIME.1HourShares / $LASTBLOCKSBYTIME.1HourEstimatedShares * 100)|number_format:"2"}%</font></b>
                {else}
                  0.00%
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.1HourAmount|number_format:"2"}</td>
                <td class="text-right">{($LASTBLOCKSBYTIME.1HourTotal|default:"0.00" / (3600 / $COINGENTIME)  * 100)|number_format:"2"}%</td>
              </tr>
              <tr>
                <th style="padding-left:3px;padding-right:1px;">最近24小时</th>
                <td class="text-right">{(86400 / $COINGENTIME)|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.24HourTotal|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.24HourValid|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.24HourOrphan|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.24HourValid > 0}
                  {($LASTBLOCKSBYTIME.24HourDifficulty / $LASTBLOCKSBYTIME.24HourValid)|number_format:"4"}
                {else}
                  0
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.24HourEstimatedShares|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.24HourShares|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.24HourEstimatedShares > 0}
                  <font color="{if (($LASTBLOCKSBYTIME.24HourShares / $LASTBLOCKSBYTIME.24HourEstimatedShares * 100) <= 100)}green{else}red{/if}">{($LASTBLOCKSBYTIME.24HourShares / $LASTBLOCKSBYTIME.24HourEstimatedShares * 100)|number_format:"2"}%</font></b>
                {else}
                  0.00%
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.24HourAmount|number_format:"2"}</td>
                <td class="text-right">{($LASTBLOCKSBYTIME.24HourTotal|default:"0.00" / (86400 / $COINGENTIME)  * 100)|number_format:"2"}%</td>
              </tr>
              <tr>
                <th>最近7天</th>
                <td class="text-right">{(604800 / $COINGENTIME)|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.7DaysTotal|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.7DaysValid|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.7DaysOrphan|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.7DaysValid > 0}
                  {($LASTBLOCKSBYTIME.7DaysDifficulty / $LASTBLOCKSBYTIME.7DaysValid)|number_format:"4"}
                {else}
                  0
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.7DaysEstimatedShares|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.7DaysShares|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.7DaysEstimatedShares > 0}
                  <font color="{if (($LASTBLOCKSBYTIME.7DaysShares / $LASTBLOCKSBYTIME.7DaysEstimatedShares * 100) <= 100)}green{else}red{/if}">{($LASTBLOCKSBYTIME.7DaysShares / $LASTBLOCKSBYTIME.7DaysEstimatedShares * 100)|number_format:"2"}%</font></b>
                {else}
                  0.00%
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.7DaysAmount|number_format:"2"}</td>
                <td class="text-right">{($LASTBLOCKSBYTIME.7DaysTotal|default:"0.00" / (604800 / $COINGENTIME)  * 100)|number_format:"2"}%</td>
              </tr>
              <tr>
                <th>最近4周</th>
                <td class="text-right">{(2419200 / $COINGENTIME)|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.4WeeksTotal|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.4WeeksValid|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.4WeeksOrphan|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.4WeeksValid > 0}
                  {($LASTBLOCKSBYTIME.4WeeksDifficulty / $LASTBLOCKSBYTIME.4WeeksValid)|number_format:"4"}
                {else}
                  0
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.4WeeksEstimatedShares|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.4WeeksShares|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.4WeeksEstimatedShares > 0}
                  <font color="{if (($LASTBLOCKSBYTIME.4WeeksShares / $LASTBLOCKSBYTIME.4WeeksEstimatedShares * 100) <= 100)}green{else}red{/if}">{($LASTBLOCKSBYTIME.4WeeksShares / $LASTBLOCKSBYTIME.4WeeksEstimatedShares * 100)|number_format:"2"}%</font></b>
                {else}
                  0.00%
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.4WeeksAmount|number_format:"2"}</td>
                <td class="text-right">{($LASTBLOCKSBYTIME.4WeeksTotal|default:"0.00" / (2419200 / $COINGENTIME)  * 100)|number_format:"2"}%</td>
              </tr>
              <tr>
                <th>最近12个月</th>
                <td class="text-right">{(29030400 / $COINGENTIME)|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.12MonthTotal|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.12MonthValid|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.12MonthOrphan|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.12MonthValid > 0}
                  {($LASTBLOCKSBYTIME.12MonthDifficulty / $LASTBLOCKSBYTIME.12MonthValid)|number_format:"4"}
                {else}
                  0
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.12MonthEstimatedShares|number_format}</td>
                <td class="text-right">{$LASTBLOCKSBYTIME.12MonthShares|number_format}</td>
                <td class="text-right">
                {if $LASTBLOCKSBYTIME.12MonthEstimatedShares > 0}
                  <font color="{if (($LASTBLOCKSBYTIME.12MonthShares / $LASTBLOCKSBYTIME.12MonthEstimatedShares * 100) <= 100)}green{else}red{/if}">{($LASTBLOCKSBYTIME.12MonthShares / $LASTBLOCKSBYTIME.12MonthEstimatedShares * 100)|number_format:"2"}%</font></b>
                {else}
                  0.00%
                {/if}
                </td>
                <td class="text-right">{$LASTBLOCKSBYTIME.12MonthAmount|number_format:"2"}</td>
                <td class="text-right">{($LASTBLOCKSBYTIME.12MonthTotal|default:"0.00" / (29030400 / $COINGENTIME)  * 100)|number_format:"2"}%</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="panel-footer">
        <h6>{if $GLOBAL.config.payout_system != 'pps'}温馨提示: 需要耐心等待 <font class="confirmations">{$GLOBAL.confirmations}</font> 个确认后才能入账.{/if}</h6>
      </div>
    </div>
  </div>
</div>
